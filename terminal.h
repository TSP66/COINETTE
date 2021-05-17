//
//  terminal.h
//  
//
//  Created by Tom Petty on 17/5/21.
//

#ifndef terminal_h
#define terminal_h

#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>

std::string exec(const char* cmd);

std::string get_colour(void);

int get_fill(void);


#endif /* terminal_h */
