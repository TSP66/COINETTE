//Wallet.c
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <unistd.h>
#include <string>
#include <math.h>

#include "csv.h"

using namespace std;

string public_key;
string private_key;

bool wallet = true;

/*******************************HASH FUNCTION USED**************************************/
const long long hash_f(string input){ //hash function used for switch case statment
    long long sum = 0;
    for(int i = 0; i < input.length(); i++){
        if(input[i] == ' '){
            sum = (sum + 1)%1000;
        }
        
        else
        sum = ((int)(sum + (((long) input[i])%10)*pow(10,(i%10))))%10000;
    }
    return(sum);
}
/***************************************************************************************************/
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
        cout << "Wallet console (type 'help' for commands and usage): ";
        string input;
        cin >> input;
        switch ((const long long) hash_f(input)) {
            case 8543://private-key
                cout << "\nPrivate Key: " + private_key + "\n\n";
                break;
                
            case 8541://Private-key
                cout << "\nPrivate Key: " + private_key + "\n\n";
                break;
                
            case 4007://address
                cout << "\nAddress: " + public_key + "\n\n";
                break;
                
            case 4005://Address
                cout << "\nAddress: " + public_key + "\n\n";
                break;
                
            case 2814: //help
                cout << "\nCommands (Case sensitive):\n     Address: returns address\n     Private-key: returns private key\n     Help: lists this message\n\n\n";
                break;
            
            case 2812: //Help
                cout << "\nCommands (Case sensitive):\n     Address: returns address\n     Private-key: returns private key\n     Help: lists this message\n\n\n";
                break;
                
            case 6573: //quit
                cout << "\nQuiting....";
                wallet = false;
                
            case 6571: //Quit
                cout << "\nQuiting....";
                wallet = false;
            
                
            default:
                cout << "\n Command: "+input+" not found, type for help for commands and usage";
                break;
        }
        
        
    }

    
    
    
    
    
    return(0);
}
