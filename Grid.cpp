#include <iostream>
#include <cmath>

#include "Grid.h"
#include "FileReader.h"

using namespace std;
Grid::Grid(){
	rows = 5;
	columns = 5;
	gridArray = new Cell*[rows];
  for(int i = 0; i < rows; i++)
      gridArray[i] = new Cell[columns];
}

Grid::Grid(int width, int height){
	rows = height;
	columns = width;
	gridArray = new Cell*[rows];
  for(int i = 0; i < rows; i++)
      gridArray[i] = new Cell[columns];
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


void Grid::filePopulate(string fileInput){
	FileReader *fr = new FileReader();
	fr->readFile(fileInput);



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

//prints grid as a string (access w fileReader class)
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
