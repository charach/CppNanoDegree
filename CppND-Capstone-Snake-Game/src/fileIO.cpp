#include <string>
#include <fstream>
#include <ostream>
#include "fileIO.h"

using std::string;

FileIO::FileIO(string filePath) : _filePath(filePath){
    _maxScore = 0;
	// read File
	ifstream scoreFile(_filePath.data());
	if(scoreFile.is_open()){
		string line;
        scoreFile >> line;
        try{
            _maxScore = std::stoi(line);
        }catch (std::invalid_argument& e){
            _maxScore = 0;
        }catch (std::out_of_range& e){
            _maxScore = 0;
        }
		scoreFile.close();
	}
}

FileIO::~FileIO(){
    ofstream scoreFile(_filePath.data());
    if(scoreFile.is_open()){
        string line = std::to_string(_maxScore);
        scoreFile.write(line.c_str(),line.size());
        scoreFile.close();       
    }
}

int FileIO::getMaxScore() const{
    return _maxScore;
}

void FileIO::setMaxScore(int score){
    if(_maxScore < score){
        _maxScore = score;
    }
}