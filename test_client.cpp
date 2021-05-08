//
//  test_client.cpp
//  
//
//  Created by Tom Petty on 15/4/21.
//


#include <iostream>
#include "connections.hpp"

CONNECTION client;

int main(){
    client.port = 8888;
    client.ip = (char *) "127.0.0.1";
    
    client.setup_as_client();
    
    while(1){
      client.SEND("hi ");
    }
     
    return(0);
}
