//
//  connections.cpp
//  
//
//  Created by Tom Petty on 23/4/21.
//

#include <thread>
#include "connections.hpp"

CONNECTION connection;

connection.port = 8336;


connection.ip = (char *) "127.0.0.1";


int main(void){
    int i = connection.boot();
    
    return(0);
}


/*
std::thread thread_objstd[4];

void connection(char c, int connection_number, std::string address)
{
    CONNECTION con;
    if(c = "s"){
        con.setup_as_server();
        server(con);
    }
    if(c = "c"){
        con.setup_as_client(address);
    }
    
}

void server(CONNECTION con){
    
}

int main(void){
    thread_obj[conenctions](connection, ("s", 0, NULL));
}

//std::thread thread_obj(connection, ("s"));
//TartAttack
*/
