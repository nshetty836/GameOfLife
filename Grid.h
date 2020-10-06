#include <iostream>
#include "Cell.h"
using namespace std;

class Grid{

  public:
    Grid();
  	Grid(int width, int height);
    Grid(string fileInput);
  	~Grid();
    Cell** gridArray;


	  void randPopulate(double popDensity);  //makes random grid
    int genRandNum(int low, int high);
    int getRows();
    int getColumns();
    Cell getCell(int row, int col);
    string toString(); //prints grid as a string (access w FileProcessor class)
    void advanceGen(); //move all Cells forward one generation
    Cell* getNeighbors(int row, int col);  //THIS IS WHAT CHANGES FOR DIFF MODES
    bool equals(Grid *g);



  private:
    int rows;
		int columns;


};
