//
//  csv.h
//  
//
//  Created by Tom Petty on 9/5/21.
//

#ifndef csv_h
#define csv_h

#include <isostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <string>

class CSV{
private:
    
    std::ofstream csv;
    
public:
    
    int * get_shape(void);
    
    int height = 0;
    int length = 0;
    
    void open(std::string name){
        csv(name, std::ios_base::app);
        length = *get_shape();
        height = *(get_shape()+1);
    }
    
    int * get_shape(void){
        int x = 0;
        int y = 0;
        int returner[2];
        std::string line;
        int max_x = 0;
        while(std::getline(myFile, line))
            {
                y++;
                for(int i = 0; i < line.length(); i++){
                    if(line[i]==',') x++;
                }
                
                if(x>max_x) max_x = x;
            }
        returner[0] = max_x;
        returner[1] = y;
        
        return(returner);
    }
    
    void add_row(std::string data){
        csv.write(data);
    }
    
    std::string get_row(int row){
        std::string line;
        int y = 0;
        while(std::getline(myFile, line))
            {

                if(y=row) return(line);
                y++;
            }
        if(y < row){
            cout << "Error: 1, Invalid Row, Possible over flow \n";
            return("-1");
        }
    }
    
    std::string get_data(int x, int y){
        std::string row = get_row(y);
        if(row = "-1"){
            return("-1");
        }
        int col = 0;
        for(int i = 0; i < x; i++){
            if(col == x){
                std::string r;
                while(1){
                    r = r + row[i]
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
            cout << "Error: 1, Invalid Row, Possible over flow \n";
            return("-1");
        }
    }
}


#endif /* csv_h */
