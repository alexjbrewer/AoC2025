#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

struct range{
	unsigned long long min = 0;
	unsigned long long max = 0;
};

bool isFresh(struct range r, unsigned long long ingredient){
	if(r.min <= ingredient && r.max >= ingredient){
		return true;
	} else {
		return false;
	}
}

int main(){
	std::ifstream fileInput;
	fileInput.open("day5.txt");
	if(!fileInput.is_open()){
		std::cout << "Error - couldn't open file!\n";
		exit(1);
	}

	std::vector<struct range> ranges;
	std::vector<unsigned long long> rangeMins;
	std::vector<unsigned long long> rangeMaxs;
	std::vector<unsigned long long> ingredients;
	std::string line;
	while(std::getline(fileInput, line)){
		std::string substring;
		std::stringstream ss(line);
		if(line.find("-") != std::string::npos){
			std::getline(ss, substring, '-');
			unsigned long long min = std::stoull(substring);
			std::getline(ss, substring);
			unsigned long long max = std::stoull(substring);
			struct range r = {min, max};
			ranges.push_back(r);
			rangeMins.push_back(min);
			rangeMaxs.push_back(max);
		} else if(line.length() > 0) {
			ingredients.push_back(std::stoull(line));
		}
	}
	int total = 0;
	for(const auto& i : ingredients){
		bool fresh = false;
		for(const auto& r : ranges){
			if(isFresh(r,i)){
				fresh = true;
			}
		}
		if(fresh){ total += 1;}
	}

	std::sort(rangeMins.begin(), rangeMins.end());
	std::sort(rangeMaxs.begin(), rangeMaxs.end());

	std::vector<struct range> newRanges;
	int depth = 0;
	struct range newRange = {0, 0};
	while((int)rangeMaxs.size() > 0){
		//std::cout << rangeMins.size() << " | " << rangeMaxs.size() << " (" << depth << ")\n";
		int prevDepth = depth;
		if((int)rangeMins.size() > 0 && rangeMins[0] <= rangeMaxs[0]){
			depth += 1;
			if(prevDepth == 0 && depth == 1){
				newRange.min = rangeMins[0];
			}
			rangeMins.erase(rangeMins.begin());
		} else{
			depth -= 1;
			if(prevDepth == 1 && depth == 0){
				newRange.max = rangeMaxs[0];
				newRanges.push_back(newRange);
			}
			rangeMaxs.erase(rangeMaxs.begin());
		}
	}
	unsigned long long part2 = 0;
	for( const auto& r : newRanges){
		//std::cout << r.min << " <--> " << r.max << "\n";
		part2 += r.max - r.min + 1;
	}
	// go thhroughh lists, act on min from next of each
	// add depthh for min, subtract for max
	// increase count if dep[thh > 0
	std::cout << "Total: " << total << "\n";
	std::cout << "Part2: " << part2 << "\n";
	return 0;
}
