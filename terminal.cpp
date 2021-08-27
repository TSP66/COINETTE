//
//  terminal.cpp
//  
//
//  Created by Tom Petty on 17/5/21.
//

#include "terminal.h"

using namespace std;

std::string exec(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}

std::string get_colour(void){
    std::string colour = exec("./background.sh");
    return(colour);
}

int get_fill_b(void){
    std::string string_colour = exec("./background.sh");
    string_colour = string_colour + '\0';
    std::string black("0000"); //Black or strong colour
    size_t found = string_colour.find(black,0);
    if(found < 100){
        return(BLACK);
    }
    else{
        return(WHITE);
    }
    
}
