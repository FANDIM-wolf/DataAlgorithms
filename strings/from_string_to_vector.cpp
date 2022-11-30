/*
 string "a+b+a+c" splits in tokens {[a][+][b][+][a][+][c]}

*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

string define_accurate_name_of_variable(string var) {
	string accurate_name;
	for (int i = 0; i <= var.length(); i++) {
		if (var[i] != ' ') {
			accurate_name += var[i];
		}
	}

	return accurate_name;
}

//returns 1 if variable already exists.
int  is_variable_already_exists(string name_of_variable) {
	
	elem object_for_checking;
	for (auto i : ELEMENTS) {
	    cout<<"NAME:"<<i.name<<" "<<name_of_variable<<endl;
	    if(name_of_variable == i.name){
	        
	        return i.value;
	    }
	}

    return 0;	
}
vector<string> from_string_to_vector(string raw_string){
    
    raw_string += "+e";
    string new_s ,supposed_string , supposed_string_value;
    int position_start_of_name = 0;
    int position_end_of_name = 0;
    int length_of_element , value_of_the_elem ;
    string math_symbol;
    vector<string> tokens;
     for(int i = 0; i<= raw_string.length()+1; i++ )
    {
    if( raw_string[i] != '+' || raw_string[i] != '-' || raw_string[i] != '/' || raw_string[i] != '*' ){
            
            supposed_string += raw_string[i];
        }
    if( raw_string[i] == '+' || raw_string[i] == '-' || raw_string[i] == '/' || raw_string[i] == '*'){
          
            
       
            position_end_of_name = i; 
            //get current element. 
            length_of_element = position_end_of_name - position_start_of_name;
            supposed_string = raw_string.substr(position_start_of_name,length_of_element);
            //supposed_string = define_accurate_name_of_variable(supposed_string); // remove spaces
            cout<<"supposed_string"<<supposed_string<<endl;
            //find supposed_string in vector of elements .
            
    
                 
                // copy string in char array 
               
                //get size of value 
                
               
                tokens.push_back(supposed_string);
                math_symbol += raw_string[i]; // erase it later.
                tokens.push_back(math_symbol); //save math symbol .
                //cout<<"after deleting spaces:"<<supposed_string<<endl;
                //value_of_the_elem = is_variable_already_exists(supposed_string);
         
          
              
                //new_s = raw_string.replace(position_start_of_name, supposed_string_value.size() , supposed_string_value);
                
                position_start_of_name = position_end_of_name+1;
         
                
                supposed_string.erase();
                cout<<"AFTER ERASE "<<supposed_string<<endl;
            
                math_symbol.erase();
                
            
            }
        }    
        

    tokens.pop_back();//delete extra plus .
        
    return tokens;
}
