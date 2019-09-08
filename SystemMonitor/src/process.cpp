#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>
#include "process.h"
#include "linux_parser.h"

using std::string;
using std::to_string;
using std::vector;

// TODO: Return this process's ID
int Process::Pid() { return pid; }

// TODO: Return this process's CPU utilization
float Process::CpuUtilization() { 
    vector<string> cpuVector = LinuxParser::CpuUtilization(pid);
    float total = 0;

    // total = utime + stime + cutime + cstime
    total = stof(cpuVector[13]) + stof(cpuVector[14]) + stof(cpuVector[15]) + stof(cpuVector[15]);
    float uptime = (float)LinuxParser::UpTime();
    float seconds = uptime - (stof(cpuVector[21]) / sysconf(_SC_CLK_TCK));
    float cpu_usage = 100 * ((total / sysconf(_SC_CLK_TCK)) / seconds);
    cpuUtil = cpu_usage;
    return cpu_usage;
}

// TODO: Return the command that generated this process
string Process::Command() { return LinuxParser::Command(pid); }

// TODO: Return this process's memory utilization
string Process::Ram() { return LinuxParser::Ram(pid); }

// TODO: Return the user (name) that generated this process
string Process::User() { return LinuxParser::User(pid); }

// TODO: Return the age of this process (in seconds)
long int Process::UpTime() { return LinuxParser::UpTime(pid); }

// TODO: Overload the "less than" comparison operator for Process objects
// REMOVE: [[maybe_unused]] once you define the function
bool Process::operator<(Process const& a) const { return this->cpuUtil  < a.cpuUtil;}