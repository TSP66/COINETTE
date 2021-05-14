//Wallet.c

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    if((access("public_key.txt", F_OK ) == 0) && (access("private_key.txt", F_OK ) == 0)) {
        // file exists
    } else {
        system("python3 ccc.py");
    }
    return(0);
}
