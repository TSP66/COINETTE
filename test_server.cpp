//test server
#include <iostream>
#include "connections.hpp"

CONNECTION server;

int main(){
  server.port = 8888;
  server.setup_as_server();
    
    while(1){
        server.READ();
        std::cout << server.output;
    }
  return(0);
}
