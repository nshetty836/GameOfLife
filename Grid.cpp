#include <iostream>
#include <cmath>
#include "Grid.h"
#include "FileProcessor.h"

using namespace std;

//default constructor
Grid::Grid(){
	rows = 5;
	columns = 5;
	gridArray = new Cell*[rows];
  for(int i = 0; i < rows; i++)
      gridArray[i] = new Cell[columns];
}
//overloaded constructor
Grid::Grid(int r, int c){
	rows = r;
	columns = c;
	gridArray = new Cell*[rows];
  for(int i = 0; i < rows; i++)
      gridArray[i] = new Cell[columns];
}
//overloaded constructor for random population
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
//overloaded constructor for file population
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
}
//destructor
Grid::~Grid(){
	delete gridArray;
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

void Grid::setGrid(Grid *g){
	for(int i = 0; i < rows; i++){
    for(int j = 0; j < columns; j++){
      gridArray[i][j].setState(g->getCell(i, j).getState());
    }
  }
}

//prints grid as a string (access w FileProcessor class)
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
// prints grid to console
void Grid::printGrid(){
	cout << this->toString() << endl;
}
// prints grid to file
void Grid::printToFile(string outFileName, int gen){
	FileProcessor *fr = new FileProcessor();
	if(gen ==1){
		fr->clearFile(outFileName);
	}
	fr->writeFile(outFileName, "Generation " + to_string(gen) + ":\n" + this->toString());
}
// checking if grid is empty
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
