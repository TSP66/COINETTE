//
//  install.cpp
//  
//
//  Created by Tom Petty on 8/5/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "terminal_color.h"


int install_depedencies(void){
    
    //Set color to black with white background
    printf(BBLK);
    printf(WHTB);
    
    printf("Installing Depedencies: Brew, Python3, GMP, Fastecdsa");
    
    printf(reset);
    printf("\n \n");

    //Set
    printf(BWHT);
    printf(BLUB);
    
    printf("Installing Brew:");
    
    
    int brew = system('/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install.sh)"');
    
    if(brew != -1){
        printf(reset);
        printf("\n");
        printf(REDB);
        printf(BWHT);
        printf("Error installing homebrew: Exiting");
       // return -1;
    }
    else{
        printf(reset);
        printf("\n");
        printf(GRNB);
        printf(BWHT);
        printf("Successfully installed homebrew");
    }
    
    printf(reset);
    printf("\n \n");

    //Set
    printf(BWHT);
    printf(BLUB);
    
    printf("Installing Python3:");
    
    int python3 = system('brew install python3');
    
    if(python3 != -1){
        printf(reset);
        printf("\n");
        printf(REDB);
        printf(BWHT);
        printf("Error installing Python3: Exiting");
        //return -1;
    }
    else{
        printf(reset);
        printf("\n");
        printf(GRNB);
        printf(BWHT);
        printf("Successfully installed Python3");
    }
    
    printf(reset);
    printf("\n \n");

    //Set
    printf(BWHT);
    printf(BLUB);
    
    printf("Installing GMP:");
    
    int gmp = system('brew install gmp');
    
    if(gmp != -1){
        printf(reset);
        printf("\n");
        printf(REDB);
        printf(BWHT);
        printf("Error installing GMP: Exiting");
        //return -1;
    }
    else{
        printf(reset);
        printf("\n");
        printf(GRNB);
        printf(BWHT);
        printf("Successfully installed GMP");
    }
    
    printf(reset);
    printf("\n \n");

    //Set
    printf(BWHT);
    printf(BLUB);
    
    printf("Installing Fastecdsa:");
    
    int fastecdsa = system('pip3 install fastecdsa');
    
    if(fastecdsa != -1){
        printf(reset);
        printf("\n");
        printf(REDB);
        printf(BWHT);
        printf("Error installing Fastecdsa: Exiting");
        //return -1;
    }
    else{
        printf(reset);
        printf("\n");
        printf(GRNB);
        printf(BWHT);
        printf("Successfully installed Fastecdsa");
    }
}

int main(void){
    install_depedencies();
    return(0);
}
