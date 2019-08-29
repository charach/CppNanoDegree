#include <string>
#include <time.h>

#include "format.h"

using std::string;

// TODO: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long seconds) {
    int hour,minutes;
    hour = minutes = 0;
    if(seconds > 3600){
        hour = seconds / 3600;
        seconds -= hour * 3600;
    }
    if(seconds > 60){
        minutes = seconds / 60;
    }
    seconds -= minutes * 60;

    return std::to_string(hour)+":"+std::to_string(minutes)+":"+std::to_string(seconds); 
}