#include <vector>
#include <iostream>
#include <fstream>
#include <string>

const char ROLL = '@';

int countAdjacent(int row, int col, std::vector<std::vector<char>> grid, int rows, int cols){
	if(grid[row][col] != ROLL){return 9999;}
	int adjacent = 0;
	if(row > 0){
		if(col > 0){
			if(grid[row-1][col-1] == ROLL){adjacent+=1;}
		}
		if(grid[row-1][col] == ROLL){adjacent+=1;}
		if(col < cols-1){
			if(grid[row-1][col+1] == ROLL){adjacent+=1;}
		}
	}
		if(col > 0){
			if(grid[row][col-1] == ROLL){adjacent+=1;}
		}
		if(col < cols-1){
			if(grid[row][col+1] == ROLL){adjacent+=1;}
		}
	if(row < rows-1){
		if(col > 0){
			if(grid[row+1][col-1] == ROLL){adjacent+=1;}
		}
		if(grid[row+1][col] == ROLL){adjacent+=1;}
		if(col < cols-1){
			if(grid[row+1][col+1] == ROLL){adjacent+=1;}
		}
	}
	return adjacent;
}

int main(){
	std::ifstream fileInput;
	fileInput.open("day4.txt");
	if(!fileInput.is_open()){
		std::cout << "Error - couldn't open file!\n";
		exit(1);
	}

	std::string line;
	std::vector<std::vector<char>> grid;
	while(std::getline(fileInput, line)){
		std::vector<char> row;
		for(int i = 0; i < (int)line.length(); i++){
			row.push_back(line[i]);
		}
		grid.push_back(row);
	}

	int total = 0;
	int removed = 99999;
	int rows = grid.size();
	int cols = grid[0].size();
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			if(countAdjacent(i,j,grid, rows, cols) < 4){
				total += 1;
			}
		}
	}
	std::cout << "Part 1: " << total << "\n";
	total = 0;
	while(removed > 0){
		removed = 0;
		for(int i = 0; i < rows; i++){
			for(int j = 0; j < cols; j++){
				if(countAdjacent(i,j,grid, rows, cols) < 4){
					grid[i][j] = 'x';
					removed += 1;
				}
			}
		}
		if(total == 0){
			std::cout << "Part 1: " << removed << "\n";
		}
		total += removed;
	}

	std::cout << "Part 2: " << total << "\n";
	return 0;
}
