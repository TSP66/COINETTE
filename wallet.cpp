//Wallet.c

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <unistd.h>

std:string public_key;
std:string private_key;

bool wallet = true;

int main(){
    
    if((access("public_key.txt", F_OK ) == 0) && (access("private_key.txt", F_OK ) == 0)) {
        // file exists
    }
    else {
        system("python3 ecc.py");
    }
    
    ifstream public_key_file("public_key.txt");
    ifstream private_key_file("private_key.txt");
    
    getline(public_key_file, public_key);
    getline(private_key_file, private_key);
    
    while(wallet){
        puts("Wallet console type help for commands and usage: ");
        
    }

    
    
    
    
    
    return(0);
}
