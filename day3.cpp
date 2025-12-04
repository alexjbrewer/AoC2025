#include <vector>
#include <iostream>
#include <fstream>
#include <string>

int main(){
	std::ifstream fileInput;
	fileInput.open("day3.txt");
	if(!fileInput.is_open()){
		std::cout << "Error - couldn't open file!\n";
		exit(1);
	}

	std::string line;
	std::vector<std::string> banks;

	while(std::getline(fileInput, line)){
		banks.push_back(line);
	}

	std::vector<int> joltages;
	for(std::string bank : banks){
		int max = 0;
		for(int i = 0; i < (int)bank.length(); i++){
			int n = bank[i]-(int)'0';
			for(int j = i+1; j < (int)bank.length() && i < (int)bank.length(); j++){
				int m = bank[j]-(int)'0';
				int val = 10*n + m;
				if(val>max){
					max=val;
				}
			}
		}
		joltages.push_back(max);
	}

	int total = 0;
	for(const auto& joltage : joltages){
		total += joltage;
	}
	std::cout << "Total: " << total << "\n";
	return 0;
}
