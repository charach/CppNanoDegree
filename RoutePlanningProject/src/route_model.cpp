#include "route_model.h"
#include <iostream>
RouteModel::RouteModel(const std::vector<std::byte> &xml) : Model(xml)
{
    int index = 0;
    for (Model::Node node : this->Nodes())
    {
        m_Nodes.push_back(RouteModel::Node(index, this, node));
        index++;
    }
}

void RouteModel::CreateNodeToRoadHashmap()
{
    for (const Model::Road &road : this->Roads())
    {
        if (road.type != Model::Road::Type::Footway)
        {
            for (int node_idx : Ways()[road.way].nodes)
            {
                if (node_to_road.find(node_idx) == node_to_road.end())
                {
                    node_to_road[node_idx] = std::vector<const Model::Road *>();
                }
                node_to_road[node_idx].push_back(&road);
            }
        }
    }
}

RouteModel::Node *RouteModel::Node::FindNeighbor(std::vector<int> node_indices)
{
    Node *closest_node = nullptr;
    for( int node_index : node_indices) {
        RouteModel::Node node = this->parent_model->SNodes()[node_index];
        if(!node.visited && this->distance(node) != 0) {
            if(closest_node == nullptr || this->distance(node) < this->distance(*closest_node)) {
                closest_node = &node;
            }
        }
    }
    return closest_node;
}

void RouteModel::Node::FindNeighbors() {
    for( auto & road : parent_model->node_to_road[this->index]) {
        RouteModel::Node *neighborNode = this->FindNeighbor(this->parent_model->Ways()[road->way].nodes);
        if( neighborNode != nullptr){
            this->neighbors.push_back(neighborNode);
        }
    }
}

RouteModel::Node &RouteModel::FindClosestNode(float x, float y) {
    RouteModel::Node tempNode;
    tempNode.x = x;
    tempNode.y = y;
    float min_dist = std::numeric_limits<float>::max();

    int closest_idx;
    for (const Model::Road &road : this->Roads()){
        if(road.type != Model::Road::Type::Footway) {
            for(int node_idx : Ways()[road.way].nodes) {
                float dist = tempNode.distance(SNodes()[node_idx]);
                if(min_dist > dist) {
                    min_dist = dist;
                    closest_idx = node_idx;
                }
            }
        }
    }
    return SNodes()[closest_idx];
}