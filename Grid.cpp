#include <iostream>
#include "Grid.h"

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

//makes random grid
void Grid::randPopulate(double popDensity) {

}
void Grid::filePopulate(string fileInput){

}
int Grid::getRows(){

}
int Grid::getColumns(){

}
Cell Grid::getCell(int row, int col){

}

//prints grid as a string (access w fileReader class)
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

//move all Cells forward one generation (this might go in the diff modes?)
void Grid::advanceGen(){

}

//THIS IS WHAT CHANGES FOR DIFF MODES
Cell* Grid::getNeighbors(int row, int col){

}
