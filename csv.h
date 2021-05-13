//
//  csv.h
//  
//
//  Created by Tom Petty on 9/5/21.
//

#ifndef csv_h
#define csv_h

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <string>

using namespace std;

class CSV{
private:
    ofstream csv_write;
    ifstream csv_read;
public:
    
    int height;
    int length;
    
    int * get_shape(void){
        height = 0;
        length = 0;
        int x = 0;
        int y = 0;
        int returner[2];
        string Line;
        int max_x = 0;
        
        while(getline(csv_read, Line))
            {
                y++;
                for(int i = 0; i < Line.length(); i++){
                    if(Line[i] == ',') x++;
                }
                
                if(x>max_x) max_x = x;
            }
        returner[0] = max_x;
        returner[1] = y;
        
        return(returner);
    }
    
    void OPEN(string name){
        csv_write.open(name, ios_base::app);
        csv_read.open(name);
        length = *get_shape();
        height = *(get_shape()+1);
    }
    
    
    void add_row(string data){
        csv_write << (data);
    }
    
    string get_row(int row){
        string Line;
        int y = 0;
        while(getline(csv_read, Line))
            {
                if(y == row) return(Line);
                y++;
            }
        if(y < row){
            cout << "Error: 1, Invalid Row, Possible over flow \n";
            return("-1");
        }
        else{
            cout << "Error: 3, Crash: Unkown Reason \n";
            return("-1");
        }
    }
    
    string get_data(int x, int y){
        string row = get_row(y);
        if(row == "-1"){
            return("-1");
        }
        int col = 0;
        int i;
        for(i = 0; i < x; i++){
            if(col == x){
                string r;
                while(1){
                    r = r + row[i];
                    if(row[i] == ','){
                        break;
                    }
                    i++;
                }
                return r;
            }
            if(row[i] == ','){
                col++;
            }
        }
        if(i < x){
            cout << "Error: 2, Invalid Column, Possible over flow \n";
            return("-1");
        }
        else{
            cout << "Error: 3, Crash: Unkown Reason \n";
            return("-1");
        }
    }
    void close(void){
        csv_write.close();
        csv_read.close();
    }
};


#endif /* csv_h */
