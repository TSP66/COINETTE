//connections.hpp

#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>

#define PORT 8080

class CONNECTION{
public:
    int port;
    char * ip;
    char * ip_address;
    char buffer[1024];
    char * output;
    char * message;
    char Data[1024];
    int sock;
    struct sockaddr_in address;
    pthread_t thread;
    
    int check(void){
        int returner = 0;
        for(int i = 0; i < 1024; i++){
            if(Data[i] != '\000') {
                returner = 1;
                break;
            }
        }
        return returner;
    }
    
    int setup_as_server(void)
    {
        int server_fd, valread;
        int opt = 1;
        int addrlen = sizeof(address);
        
        
        
        // Creating socket file descriptor
        if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
        {
            perror("socket failed");
            exit(EXIT_FAILURE);
        }
        
        // Forcefully attaching socket to the port 8080
        /*if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                                                    &opt, sizeof(opt)))
        {
            perror("setsockopt");
            exit(EXIT_FAILURE);
        }
    */
        address.sin_family = AF_INET;
        address.sin_addr.s_addr = INADDR_ANY;
        address.sin_port = htons(PORT);
        
        // Forcefully attaching socket to the port 8080
        if (bind(server_fd, (struct sockaddr *)&address,
                                    sizeof(address))<0)
        {
            perror("bind failed");
            exit(EXIT_FAILURE);
        }
        if (listen(server_fd, 3) < 0)
        {
            perror("listen");
            exit(EXIT_FAILURE);
        }
        if ((sock = accept(server_fd, (struct sockaddr *)&address,
                        (socklen_t*)&addrlen))<0)
        {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        ip_address = inet_ntoa(address.sin_addr);
        puts(ip_address);
    return 0;
        
    }



    int setup_as_client(void)
    {
        int valread;
        struct sockaddr_in serv_addr;
        //struct sockaddr_in serv_addr;
         
        if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        {
            printf("\n Socket creation error \n");
            return -1;
        }

        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(port);
        
        // Convert IPv4 and IPv6 addresses from text to binary form
        if(inet_pton(AF_INET, ip, &serv_addr.sin_addr)<=0)
        {
            printf("\nInvalid address/ Address not supported \n");
            return -1;
        }

        if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        {
            //printf("\n Setting up as server \n");
            return -1;
        }
     
    return sock;

    }

    void SEND(const char * MESSAGE){
            send(sock , MESSAGE , strlen(MESSAGE) , 0 );

    }

    void READ(void){
        clear();
        int valread;
        while(check() == 0){
            valread = read(sock , Data, 1024);
        }
        //printf("Data: ");
        //printf("%s", Data);

        output = Data;
            
            
    }

    int boot(void){
     //printf("Data: ")
     int b = 0;
     sock = setup_as_client();
        
     if(sock == -1){
         setup_as_server();
         b = 1;
    }
    return b;
    }

    void clear(void){
       for(int i = 0; i < 1024; i++){
           Data[i]  = '\000' ;
            buffer[i] = '\000' ;
    }


    }

    void Close(void){ close(sock); }
    void wipe_sockets(void){ clear(); SEND(""); }

};


//fda0:3e59:2ef8::6892:4d75:e33c:8d3d
//14.2.157.137
//10.1.1.209

 

  
