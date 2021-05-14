//
//  build_hashes.cpp
//  
//
//  Created by Tom Petty on 14/5/21.
//

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

const long long hash_f(string input){ //hash function used for switch case statment
    long long sum = 0;
    for(int i = 0; i < input.length(); i++){
        if(input[i] == ' ')
            sum = (sum + 1)%1000;
        else
        sum = ((int) (sum + (((long) input[i])%10)*pow(10,(i%10))) % 10000);
    }
    return(sum);
}

int main(void){
    while(1){
        string x;
        cin >> x;
        cout << x;
        string f;
        f = to_string(hash_f(x));
        cout << "\n"+f+"\n";
    }
    return 0;
}
