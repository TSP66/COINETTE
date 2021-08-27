//
//  time.h
//
//
//  Created by Tom Petty on 14/5/21.
//

#ifndef time_h
#define time_h

#include <time.h>

long long get_time_y2k_s(void){
    time_t timer;
    struct tm y2k = {0};
    long long seconds;

    y2k.tm_hour = 0;   y2k.tm_min = 0; y2k.tm_sec = 0;
    y2k.tm_year = 100; y2k.tm_mon = 0; y2k.tm_mday = 1;

    time(&timer);  /* get current time; same as: timer = time(NULL)  */

    seconds = difftime(timer,mktime(&y2k));

    return(seconds);
}

#endif /* time_h */
