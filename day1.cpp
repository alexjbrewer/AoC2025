#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

int main(){
	std::ifstream fileInput;
	std::string line;
	std::string LEFT = "L";
	std::string RIGHT = "R";
	int zeroCount = 0;
	int zeroClickCount = 0;

	fileInput.open("day1.txt");
	if(!fileInput.is_open()){
		std::cout << "Error - couldn't open file!\n";
		exit(1);
	}
	int currentPos = 50;
	int delta = 0;
	bool turnLeft = true;
	while(std::getline(fileInput, line)){
		if(line.substr(0,1) == LEFT){
			turnLeft = true;
		} else {
			turnLeft = false;
		}
		line.erase(0,1);
		delta = std::stoi(line);
		if(turnLeft){
			delta *= -1;
		}
		int temp = delta;
		while(temp!= 0){
			if(currentPos < 0){currentPos += 100;}
			if(currentPos > 99){currentPos -= 100;}
			if(currentPos == 0 && temp != 0){
				zeroClickCount += 1;
			}
			if(temp > 0){
				currentPos += 1;
				temp -= 1;
			}
			if(temp < 0){
				currentPos -= 1;
				temp += 1;
			}
		}
		//currentPos += delta;
		while(currentPos < 0){
			currentPos += 100;
		}
		while(currentPos > 99){
			currentPos -= 100;
		}
		if(currentPos == 0){
			zeroCount += 1;
		}

		//std::cout << turnLeft << " : " << delta  << " --> " << currentPos<< std::endl;

	}
	std::cout << "Password: " << zeroCount << std::endl;
	std::cout << "(new!)Password: " << zeroClickCount << std::endl;

	return 0;
}
