//
//  test_client.cpp
//  
//
//  Created by Tom Petty on 15/4/21.
//

#include <string>
#include "connections.hpp"
#include "sha256.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <cmath>
#include <sstream>

#define NAME "COINETTE"

#define VERSION "V.0.1"

#define difficulty 21
#define block_number 291
#define reward 10

#define split 0.1 //The fraction that goes to the miner
#define bid 9


std::string header = NAME;

char block[200];

std::string chain;

int get_digits(int num);
int internal_get_digits(int number, int point);
int Randoms(int lower, int upper);
std::string long_to_string(long long value);
std::string double_to_string(long double value);


const int transacations = 500;

/*
char *senders_address[transacations] = { "016ac903ed60e3b2daf89610ba1c64c8544df759bdd5218eb4bd95cc450d9db8",
    "016ac903ed60e3b2daf89610ba1c64c8544df759bdd5218eb4bd95cc450d9db8",
    "016ac903ed60e3b2daf89610ba1c64c8544df759bdd5218eb4bd95cc450d9db8",
    "016ac903ed60e3b2daf89610ba1c64c8544df759bdd5218eb4bd95cc450d9db8",
    "016ac903ed60e3b2daf89610ba1c64c8544df759bdd5218eb4bd95cc450d9db8",
};

char *recivers_address[transacations] = {"d3eba9345f92621ef596bb0819e2030d8794e772d3762684d45080555baf7ca3",
    "d3eba9345f92621ef596bb0819e2030d8794e772d3762684d45080555baf7ca3",
    "d3eba9345f92621ef596bb0819e2030d8794e772d3762684d45080555baf7ca3",
    "d3eba9345f92621ef596bb0819e2030d8794e772d3762684d45080555baf7ca3",
    "d3eba9345f92621ef596bb0819e2030d8794e772d3762684d45080555baf7ca3"
};


char *miners_address[transacations] = {"86a2902bb295ca66eb166abcd6eb5a86646dc18e41b03918be4f5308017aaa47",
"86a2902bb295ca66eb166abcd6eb5a86646dc18e41b03918be4f5308017aaa47",
"86a2902bb295ca66eb166abcd6eb5a86646dc18e41b03918be4f5308017aaa47",
"86a2902bb295ca66eb166abcd6eb5a86646dc18e41b03918be4f5308017aaa47",
"86a2902bb295ca66eb166abcd6eb5a86646dc18e41b03918be4f5308017aaa47"

};

char *senders_signature[transacations] = { "397eb05607c41db8a1ebb2a2c27f06998e9b2a31be71db2167d24c8b5c879e6c509c71c5bf2562fc642cc4efd585b54981306cd96bbc29e50c04748e05562008","397eb05607c41db8a1ebb2a2c27f06998e9b2a31be71db2167d24c8b5c879e6c509c71c5bf2562fc642cc4efd585b54981306cd96bbc29e50c04748e05562008","397eb05607c41db8a1ebb2a2c27f06998e9b2a31be71db2167d24c8b5c879e6c509c71c5bf2562fc642cc4efd585b54981306cd96bbc29e50c04748e05562008","397eb05607c41db8a1ebb2a2c27f06998e9b2a31be71db2167d24c8b5c879e6c509c71c5bf2562fc642cc4efd585b54981306cd96bbc29e50c04748e05562008","397eb05607c41db8a1ebb2a2c27f06998e9b2a31be71db2167d24c8b5c879e6c509c71c5bf2562fc642cc4efd585b54981306cd96bbc29e50c04748e05562008"};
*/
int value[transacations] = {120,120,120,120,120};
int transation_cost[transacations] = {8,8,8,8,8};

std::string miners_address = "86a2902bb295ca66eb166abcd6eb5a86646dc18e41b03918be4f5308017aaa47";
std::string bidders_address = "016ac903ed60e3b2daf89610ba1c64c8544df759bdd5218eb4bd95cc450d9db8";
std::string bidders_signature = "397eb05607c41db8a1ebb2a2c27f06998e9b2a31be71db2167d24c8b5c879e6c509c71c5bf2562fc642cc4efd585b54981306cd96bbc29e50c04748e05562008";


std::string recievers_address = "d4f986124bc3a6075346b15c773ee6df1fba39f01167387e9cfadf7cc37450e9";
std::string senders_address= "d3eba9345f92621ef596bb0819e2030d8794e772d3762684d45080555baf7ca3";


const long long total_shares = 19200;

const long long share_holders = 381;

std::string SEPERATOR = "|";

int main ()
{
    //Build header
    //time_t seconds;
    header = header + SEPERATOR;
    
    header = header + VERSION;
    
    header = header + SEPERATOR;
    
    long long seconds = (long long) time(NULL);
    
    std::string TIME = long_to_string(seconds);
    
    header = header + "Time:";
   
    header = header + TIME;
    
    header = header + SEPERATOR;
    
    header = header + "Block_Number:";
    
    header = header + long_to_string((long long) block_number);
    
    header = header + SEPERATOR;
    
    header = header + "Difficulty:";
    
    header = header + long_to_string((long long) difficulty);
    
    header = header + SEPERATOR;
    
    header = header + "Reward:";
    
    header = header + long_to_string((long long) reward);
    
    header = header + SEPERATOR;
    
    header = header + "Split:";
    
    header = header + double_to_string((long double) split);
    
    header = header + SEPERATOR;
    
    header = header + "Miner:";
    
    header = header + miners_address;
    
    header = header + SEPERATOR;
    
    header = header + "Bid:";
    
    header = header + long_to_string((long long) bid);
    
    header = header + SEPERATOR;
    
    header = header + "Bidder:";
    
    header = header + bidders_address;
    
    header = header + SEPERATOR;
    
    header = header + "Bidder_Signature:";
    
    header = header + bidders_signature;
    
    header = header + SEPERATOR;
    
    header = header + "Total_Shares:";
    
    header = header + long_to_string((long long) total_shares);
    
    header = header + SEPERATOR;
    
    header = header + "Shares_holders:";
    
    header = header + long_to_string((long long) share_holders);
    
    header = header + SEPERATOR;
    
    for(unsigned long long i = 0; i < share_holders; i++){
        
        header = header + "Number:";
        
        header = header + long_to_string((long long) i);
        
        header = header + SEPERATOR;
        
        header = header + "Address:";
        
        header = header + sha256(long_to_string((long long) i));
        
        header = header + SEPERATOR;
        
        header = header + "Shares:";
        
        header = header + long_to_string(i); //Dummy
        
        header = header + SEPERATOR;
        
        header = header + "Payout:";
        
        header = header + double_to_string((double)( (double) i/ (double) total_shares)* (double) ( (double) bid + (double) reward* (double) (1-(double)split)));
        
        header = header + SEPERATOR;
        
    }
    
    header = header + "Transactions:";
    
    header = header + SEPERATOR;
    
    for(int i = 0; i < transacations; i++){
        
        header = header + "Number:";
        
        header = header + long_to_string((long long) i);
        
        header = header + SEPERATOR;
        
        header = header + "Value:";
        
        header = header + double_to_string((double) 10000/ (double) ((double) i+1)); //Dummy
        
        header = header + SEPERATOR;
        
        header = header + "Recievers_Address:";
        
        header = header + recievers_address;
        
        header = header + SEPERATOR;
        
        header = header + "Senders_Address:";
        
        header = header + senders_address;
        
        header = header + SEPERATOR;
        
        
        
        
        
        
    }

    
    std::cout << header;
    std::cout << "\n \n \n";
    std::cout << sha256(header);
    
    
    
    
    
    //printf("%lld", seconds);
    
    
    
    return(0);
}
int get_digits(int num){
    return (internal_get_digits(num, 0));
}
int internal_get_digits(int number, int point){ //function only for internal use
    if(floor(number/10) < 2){
        return point;
    }
    else{
        return(internal_get_digits(floor(number/10), point++));
    }
}
int Randoms(int lower, int upper)
{
   int num = (rand() %(upper - lower + 1)) + lower;
   return(num);

}

std::string long_to_string(long long value){
    std::stringstream ss;
    ss << value;
    std::string x;
    ss >> x;
    return(x);
}

std::string double_to_string(long double value){
    
    std::string x = std::to_string(value);
    return(x);
    
    
}
/*char * int_to_char(int * INT, int length){
    char * CHAR;
    for(int i = 0; i < length; i++){
        *(CHAR+i) = *(INT + i) + *zero;
    }
    return(CHAR);
}
int * long_to_int_array(long long LONG){
    int * returner;
    long long x = LONG;
    int length = floor(log10(x));
    for(int i = 0; i < length; i++){
        int base = floor(log10(x));
        int number = floor(pow(x/10, base));
        *(returner+i) = base;
        x = x - number*(pow(10, base));
    }
    return(returner);
}
int get_length(long long x){
    return(floor(log10(x)));
}
*/
//5c7a8c11640b6f9ec22eafba5ca5634ac17d66bc7d083eaf79722e012e15467b
