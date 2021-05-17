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
#include "terminal_color.h"
#include "string_converter.h"

using namespace std;

string public_key;
string private_key;

bool wallet = true;


void format_time(void){ //Print Time function from https://stackoverflow.com/questions/5141960/get-the-current-time-in-c/5142028 user hexinpeter
    time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );

    printf("[%d-%d-%d %d:%d:%d]",timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
    cout << " ";
}

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
    
    bool time = true;
    
    while(wallet){
        format_time();
        if(time){
            cout << (char_to_string(BWHT)+"\e[48;5;$038m"+"Coinette Wallet console"+reset+" "+"(type 'help' for commands and usage):"+reset+" ");
            time = false;
        }
        else{
            cout << char_to_string(BWHT)+"\e[48;5;$038m"+"Coinette Wallet console:"+reset+" ";
        }
        string input;
        cin >> input;
        cout << "\n";
        format_time();
        switch ((const long long) hash_f(input)) {
            case 8543://private-key
                cout << "Private Key: " + private_key + "\n\n";
                break;
                
            case 8541://Private-key
                cout << "Private Key: " + private_key + "\n\n";
                break;
                
            case 4007://address
                cout << "Address: " + public_key + "\n\n";
                break;
                
            case 4005://Address
                cout << "Address: " + public_key + "\n\n";
                break;
                
            case 2814: //help
                cout << "Commands (Case sensitive):\n\n                     Address: returns address\n                     Private-key: returns private key\n                     Help: lists this message\n\n\n";
                break;
            
            case 2812: //Help
                cout << "Commands (Case sensitive):\n\n                     Address: returns address\n                     Private-key: returns private key\n                     Help: lists this message\n\n\n";
                break;
                
            case 6573: //quit
                cout << "Quiting....";
                wallet = false;
                
            case 6571: //Quit
                cout << "Quiting....";
                wallet = false;
            
                
            default:
                cout << "Command: "+input+" not found, type for help for commands and usage\n\n";
                break;
        }
        
        
    }

    
    
    
    
    
    return(0);
}
