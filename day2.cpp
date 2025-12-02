#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

struct Range{
	unsigned long long start;
	unsigned long long end;
};

bool isValidId(unsigned long long idInt){
	std::string idString = std::to_string(idInt);
	int idLength = idString.length();
	if(idLength%2 == 1){
		return true;
	}
	for(int i = 0; i < idLength / 2; i++){
		if(idString[i] != idString[i + (idLength / 2)]){
			return true;
		}
	}

	return false;
}
bool isValidIdPart2(unsigned long long idInt){
	std::string idString = std::to_string(idInt);
	int idLength = idString.length();

	for(int sublength = 1; sublength < idLength; sublength++){
		if(idLength % sublength != 0){ continue; }
		bool subIsValid = false;
		
		std::string idPattern = idString.substr(0, sublength);
		for(int j = 1; j < idLength / sublength; j++){
			if(idString.substr(j*sublength, sublength) != idPattern){
				subIsValid = true;
			}
			
		}
		if(!subIsValid){return false;}
	}

	return true;
}

int main(){
	std::ifstream fileInput;
	fileInput.open("day2.txt");
	if(!fileInput.is_open()){
		std::cout << "Error - couldn't open file!\n";
		exit(1);
	}

	std::string line;
	std::vector<unsigned long long> invalidIds;
	std::vector<unsigned long long> part2;
	std::vector<struct Range> idRanges;

	while(std::getline(fileInput, line, ',')){
		std::string substring;
		struct Range currentRange;
		std::stringstream ss(line);
		std::getline(ss,substring, '-');
		currentRange.start = std::stoull(substring);
		std::getline(ss,substring);
		currentRange.end = std::stoull(substring);
		idRanges.push_back(currentRange);
	}

	for(const auto& range : idRanges){
		//std::cout << range.start << " <--> " << range.end << "\n";
		for(unsigned long long i = range.start; i <= range.end; i++){
			if(!isValidId(i)){
				invalidIds.push_back(i);
			}
			if(!isValidIdPart2(i)){
				part2.push_back(i);
			}

		}
	}

	unsigned long long total = 0;
	unsigned long long total2 = 0;
	for(const auto& invalid : invalidIds){
		//std::cout << invalid << "\n";
		total += invalid;
	}
	for(const auto& invalid : part2){
		total2 += invalid;
	}
	std::cout << "Total: " << total << "\n";
	std::cout << "Total (part 2): " << total2 << "\n";
	return 0;
}
