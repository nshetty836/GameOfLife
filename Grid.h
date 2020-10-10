#include <iostream>
#ifndef GRID_H
#define GRID_H
#include "Cell.h"
using namespace std;

class Grid{

  public:
    Grid();
    Grid(int r, int c);
  	Grid(int r, int c, double popDensity);
    Grid(string fileInput);
  	~Grid();

    int genRandNum(int low, int high);
    int getRows();
    int getColumns();
    Cell getCell(int row, int col);
    string toString(); 
    bool equals(Grid *g);
    void printGrid();
    void printToFile(string outFileName, int gen);
    void setGrid(Grid *g);
    bool isEmpty();

    Cell** gridArray;

  private:
    int rows;
		int columns;

};
#endif
