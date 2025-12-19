#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

// TODO: Fix this to handle variable column widths in puzzle input

unsigned long long sum(std::vector<unsigned long long> list){
	unsigned long long sum = 0;
	for(unsigned long long x : list){
		sum += x;
	}
	return sum;
}

unsigned long long product(std::vector<unsigned long long> list){
	unsigned long long product = 1;
	for(unsigned long long x : list){
		product *= x;
	}
	return product;
}

class Problems{
public:
	Problems(std::string);
	std::vector<unsigned long long> calculateColumns();
private:
	std::vector<std::vector<char>> grid;
	std::vector<std::vector<unsigned long long>> columns;
	std::vector<char> operations;
	int gridRows = 0;
	int columnWidth = 0;
	int columnGroups = 0;
	void makeColumns();
};

Problems::Problems(std::string filename){
	std::ifstream fileInput;
	fileInput.open(filename);
	if(!fileInput.is_open()){
		std::cout << "Error - couldn't open file!\n";
		exit(1);
	}

	std::string line;
	while(std::getline(fileInput, line)){
		std::vector<char> gridLine;
		if(line[0] == '*' or line[0] == '+'){
			for(char c : line){
				if(c not_eq ' '){
					columnGroups++;
					operations.push_back(c);
				}
			}
		} else {
			for(char c : line){
				gridLine.push_back(c);
			}
			grid.push_back(gridLine);
		}
	}
	fileInput.close();
	columnWidth = 3;//(grid[0].size() + 1) / columnGroups - 1;
	gridRows = grid.size();
	std::cout << "Column width: " << columnWidth << "\n";
	std::cout << "Column groups: " << columnGroups << "\n";

	makeColumns();
}

void Problems::makeColumns(){
	for(int c = 0; c < columnGroups; c++){
		std::vector<unsigned long long> column;
		for(int r = 0; r < gridRows; r++){
			std::string num = "";
			for(int dx = 0; dx < columnWidth; dx++){
				num += grid[r][c + c*columnWidth + dx];
			}
			std::cout << "[" << num << "]\n";
			column.push_back(std::stoull(num));
		}
		columns.push_back(column);
	}
}

std::vector<unsigned long long> Problems::calculateColumns(){
	std::vector<unsigned long long> results;
	for(int i = 0; i < (int)columns.size(); i++){
		if(operations[i] == '+'){
			results.push_back(sum(columns[i]));
		} else{
			results.push_back(product(columns[i]));
		}
	}
	return results;
}

int main(){
	Problems problems("Day6.txt");
	std::vector<unsigned long long> results = problems.calculateColumns();
	std::cout << "Total: " << sum(results) << "\n";



	return 0;
}
