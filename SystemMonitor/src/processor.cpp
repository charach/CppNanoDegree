#include <string>
#include <vector>
#include "processor.h"
#include "linux_parser.h"

using std::string;
using std::vector;

// TODO: Return the aggregate CPU utilization
float Processor::Utilization() {
  vector<string> cpuVector = LinuxParser::CpuUtilization();

  float total = 0;
  float idle = 0;
  for (unsigned int idx = 1; idx < 10; idx++) {
    total += stof(cpuVector[idx]);
  }
  idle = stof(cpuVector[4]) + stof(cpuVector[5]);

  float totald = total - prevTotal;
  float idled = idle - prevIdle;
  prevTotal = total;
  prevIdle = idle;

  return (totald - idled) / totald;
}