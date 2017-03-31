#include <fstream>
#include <string>
#include <sstream>
#include <cassert>
#include <cctype>
#include "linkedStack.h"

int main () {
    linkedStack <double> Stack;
    string line;
    string token;
    string filename;
    int StackSize;
    double num1,num2;
    istringstream inss;
    
    ifstream infs;
    ofstream outfs;
  
    while (filename!="file.txt") {
    	cout << "Please enter file name to open " << endl;
  		getline(cin, filename); 
		infs.open(filename.c_str());   		   	
   }
   
   outfs.open("newfile.txt");
   	
   	//my postfix calculator is only working for one line.
   	//returns 0 on 2nd and 3rd line I could not solve it.
  	
    int j=0;
    while(getline(infs,line,'\n')){
    	inss.clear();
    	inss.str(line);
    	cout << line << endl;
		   	
		while(numSpaces(line) > j){ 
			inss >> token;
			char tmp = token[0];
			
			if (isdigit(tmp)){
    			Stack.push(atof(token.c_str()));
			}
			else{
				num2 = Stack.topElement();
				Stack.pop();
				num1 = Stack.topElement();
				Stack.pop();
			
				switch (tmp){
					case '+': Stack.push(num1 + num2);
						break;
					case '-': Stack.push(num1 - num2);
						break;
					case '*': Stack.push(num1 * num2);
						break;
					case '/': Stack.push(num1 / num2);
						break;
				}
			}	
			j++;	
		}
		outfs << line << " is " << Stack.pop() << endl;	
	}

	infs.close();
    outfs.close();
    return 0;
}

