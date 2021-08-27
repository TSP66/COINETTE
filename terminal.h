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

#define BLACK 0
#define WHITE 1

std::string exec(const char* cmd);

std::string get_colour(void);

int get_fill_b(void);


#endif /* terminal_h */
