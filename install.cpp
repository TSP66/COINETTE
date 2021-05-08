//
//  install.cpp
//  
//
//  Created by Tom Petty on 8/5/21.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void install_depedencies(void){
    
    cout << "Installing Depedencies: Brew, Python3, GMP, Fastecdsa\n";
    
    system('/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install.sh)"');
    system('brew install python3');
    system('brew install gmp');
    system('pip3 install fastecdsa');
}
