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
    string file_name;
public:
    
    bool FILE_OPEN;
    
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
        csv_read.open(name);
        csv_write.open(name, ios_base::app);
    
        //length = *get_shape();
        //height = *(get_shape()+1);
        file_name = name;
    }
    
    
    void ADD_ROW(string data){
        csv_write << (data) << "\n";
    }
    
    string GET_ROW(string name, int row){
        OPEN(name);
        string Line;
        int y = 0;
        while(getline(csv_read, Line))
            {
                if(y == row){
                    return(Line);
                    y++;
                    break;
                }
                y++;
            }
        if(y < row){
            cout << "Error: 1, ID: csv.h:get_row, Invalid Row, Possible over flow \n";
            return("-1");
        }
        else{
            cout << "Error: 3, ID: csv.h:get_row, Crash: Unkown Reason \n";
            return("-1");
        }
        CLOSE();
    }
    
    string GET_DATA(string name, int x, int y){
        string row = GET_ROW(name, y);
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
            cout << "Error: 2, ID: csv.h:get_data, Invalid Column, Possible over flow \n";
            return("-1");
        }
        else{
            cout << "Error: 3, D: csv.h:get_data, Crash: Unkown Reason \n";
            return("-1");
        }
    }
    void CLOSE(void){
        csv_write.close();
        csv_read.close();
    }
};


#endif /* csv_h */
