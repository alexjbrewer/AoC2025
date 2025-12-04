#include <vector>
#include <iostream>
#include <fstream>
#include <string>

std::string getBiggestValue(std::string s, int depth){
	int maxval = 0;
	int maxpos = 0;
	for(int i = 0; i < (int)s.length()-depth; i++){
		int val = s[i] - '0';
		if(maxval < val){
	 		maxval = val;
			maxpos = i;
		}
	}
	std::string biggest = "";
	if(depth > 0){
		std::string substring = s.substr(maxpos+1,s.length()-maxpos-1);
		biggest = getBiggestValue(substring, depth - 1);
	}
	return std::to_string(maxval) + biggest;
}

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

	std::vector<unsigned long long> joltages;
	for(std::string bank : banks){
		joltages.push_back(std::stoull(getBiggestValue(bank,11)));
	}

	unsigned long long total = 0;
	for(const auto& joltage : joltages){
		total += joltage;
	}
	std::cout << "Total: " << total << "\n";
	return 0;
}
