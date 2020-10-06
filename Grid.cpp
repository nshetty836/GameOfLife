#include <iostream>
#include <cmath>

#include "Grid.h"
#include "FileProcessor.h"

using namespace std;
Grid::Grid(){
	rows = 5;
	columns = 5;
	gridArray = new Cell*[rows];
  for(int i = 0; i < rows; i++)
      gridArray[i] = new Cell[columns];
}

Grid::Grid(int r, int c){
	rows = r;
	columns = c;
	gridArray = new Cell*[rows];
  for(int i = 0; i < rows; i++)
      gridArray[i] = new Cell[columns];
}

Grid::Grid(string fileInput){
	FileProcessor *fr = new FileProcessor();
	fr->readFile(fileInput);
	rows = fr->rows;
	columns = fr->columns;
	gridArray = new Cell*[rows];
  for(int i = 0; i < rows; i++)
      gridArray[i] = new Cell[columns];

	int count = 0;
	for(int i = 0; i < fr->rows; i++){
		for(int j = 0; j < fr->columns; j++){
			if(fr->allCells[count] != ' ' && fr->allCells[count] == 'X'){
				gridArray[i][j].setAlive();
			}
			count++;
		}
	}

	// for (int i = 0; i < fr->gridSize; i++) {
  //   if(allCells[i] != ' ')
  //     gridCells[i] = allCells[i];
  // }
  // for (int i = 0; i < gridSize; i++) {
  //   cout << gridCells[i];
  // }

}

Grid::~Grid(){

}

int Grid::genRandNum(int low, int high){
	return (rand() % (high - low + 1)) + low;
}

//makes random cell grid given a population density
void Grid::randPopulate(double popDensity) {
	int numAlive = round(popDensity * rows * columns);
	cout << numAlive << endl; 	//TEST
	for(int i = 0; i < numAlive; i++){
		int num1 = genRandNum(0,rows-1);
		int num2 = genRandNum(0,columns-1);
		if(gridArray[num1][num2].getState() == false)
			gridArray[num1][num2].setAlive();
		else
			i--;
	}
	cout << this->toString();
}


int Grid::getRows(){
	return rows;
}
int Grid::getColumns(){
	return columns;
}
Cell Grid::getCell(int row, int col){
	return gridArray[row][col];
}

//prints grid as a string (access w FileProcessor class)
bool Grid::equals(Grid *g){
	bool equals = false;
	if(rows == g->getRows() && columns == g->getColumns()){
		for(int i = 0; i < rows; i++){
	    for(int j = 0; j < columns; j++){
				if(this->gridArray[i][j].getState() == g->gridArray[i][j].getState())
					equals = true;
				else
					return false;

			}
		}
	}
	return equals;
}

//move all Cells forward one generation (this might go in the diff modes?)
void Grid::advanceGen(){

}

//THIS IS WHAT CHANGES FOR DIFF MODES
Cell* Grid::getNeighbors(int row, int col){

}

void Grid::clearGrid(){
	for(int i = 0; i < rows ; i++){
		for(int j = 0; j < columns; j++){
			gridArray[i][j].setDead();
		}
	}
}

string Grid::toString(){
	string ret = "";
	for(int i = 0; i < rows; i++){
    for(int j = 0; j < columns; j++){
       ret += gridArray[i][j].toString() + " ";
		}
		ret += "\n";
	}
	return ret;
}
