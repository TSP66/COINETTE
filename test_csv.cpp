//
//  test_csv.cpp
//  
//
//  Created by Tom Petty on 11/5/21.
//

#include "csv.h"

CSV csv;
CSV csv2;

int main(void){
    csv.OPEN("test_csv.csv");
    csv.ADD_ROW("hi,hi,hi,hi");
    csv.CLOSE();
    
    string x = csv.GET_ROW("test_csv.csv", 2);
    cout << x;
    return(0);
}
