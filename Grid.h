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
    Cell** gridArray;



    int genRandNum(int low, int high);
    int getRows();
    int getColumns();
    Cell getCell(int row, int col);
    string toString(); //prints grid as a string (access w FileProcessor class)
    void advanceGen(); //move all Cells forward one generation
    Cell* getNeighbors(int row, int col);  //THIS IS WHAT CHANGES FOR DIFF MODES
    bool equals(Grid *g);
    void clearGrid();
    void printGrid();
    void printToFile(string outFileName, int gen);
    void setGrid(Grid *g);
    bool isEmpty();

  private:
    int rows;
		int columns;

};
#endif
