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

Grid::Grid(int r, int c, double popDensity){
	rows = r;
	columns = c;
	gridArray = new Cell*[rows];
  for(int i = 0; i < rows; i++)
      gridArray[i] = new Cell[columns];

	int numAlive = round(popDensity * rows * columns);
	for(int i = 0; i < numAlive; i++){
		int num1 = genRandNum(0,rows-1);
		int num2 = genRandNum(0,columns-1);
		if(gridArray[num1][num2].getState() == false)
			gridArray[num1][num2].setAlive();
		else
			i--;
	}
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

void Grid::setGrid(Grid *g){
	for(int i = 0; i < rows; i++){
    for(int j = 0; j < columns; j++){
      gridArray[i][j].setState(g->getCell(i, j).getState());
    }
  }
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

void Grid::printGrid(){
	cout << this->toString() << endl;
}

void Grid::printToFile(string outFileName, int gen){
	FileProcessor *fr = new FileProcessor();
	if(gen ==1){
		fr->clearFile(outFileName);
	}
	fr->writeFile(outFileName, "Generation " + to_string(gen) + ":\n" + this->toString());
}

bool Grid::isEmpty(){
	bool ret = true;
	for(int i = 0; i < rows ; i++){
		for(int j = 0; j < columns; j++){
			if(gridArray[i][j].getState() == true)
				ret = false;
		}
	}
	return ret;
}
