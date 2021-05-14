//
//  connections.cpp
//  
//
//  Created by Tom Petty on 23/4/21.
//


#include "csv.h"
#include "connections.hpp"
#include "time.h"

void server(CONNECTION con);
void client(CONNECTION con);

CSV csv;

CONNECTION connection;

//*****************Dummy Varibles*****************//

std::string public_address = "20053020608649230331723442089943129241597707800309205888496491961204729412316";

//************************************************//

int main(void){
    
    //*****************Dummy Varibles*****************//

    connection.port = 8336;

    connection.ip = (char *) "127.0.0.1";

    //************************************************//
    
    int i = connection.boot();
    if(i){
        server(connection);
    }
    else{
        client(connection);
    }
    return(0);
}

void server(CONNECTION con){
    
    std::string address = con.READ();
    std::string ip_as_string(con.ip_address);
    con.SEND(public_address);
    csv.OPEN("connections.csv");
    std::string append = address + ',' + ip_as_string;
    csv.ADD_ROW(append);
    csv.CLOSE();
    
    while(1){
        std::string data = con.READ();
    }
    
}
void client(CONNECTION con){
    
    std::string ip_as_string(con.ip);
    con.SEND(public_address);
    std::string address = con.READ();
    csv.OPEN("connections.csv");
    std::string append = address + ',' + ip_as_string;
    csv.ADD_ROW(append);
    csv.CLOSE();
    
    while(1){
        long long seconds = get_time_y2k_s();
        
        if(seconds % 3){ //Ask for new data every 3 seconds
            
        }
    }
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
