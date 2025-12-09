#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>



int main(){
        std::ifstream fileInput;
        fileInput.open("day9.txt");
        if(!fileInput.is_open()){
                std::cout << "Error - couldn't open file!\n";
                exit(1);
        }

        
        std::string line;
        while(std::getline(fileInput, line)){
                
                 
                
        }

        return 0;
}