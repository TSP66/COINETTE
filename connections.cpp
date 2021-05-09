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


//*****************Dummy Varibles*****************//

connection.ip = (char *) "127.0.0.1";

std::string public_address = "20053020608649230331723442089943129241597707800309205888496491961204729412316";

//************************************************//


void server(connection con){
    std::string address = con.READ();
    con.SEND(public_address);
}
void clinet(connection con){
    con.SEND(public_address);
    std::string address = con.READ();
}

int main(void){
    
    int i = connection.boot();
    if(i){
        server(connection);
    }
    else{
        client(connection);
    }
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
