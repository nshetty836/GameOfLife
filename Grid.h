#include <iostream>
#include "Cell.h"
using namespace std;

class Grid{

  public:
    Grid();
  	Grid(int width, int height);
  	~Grid();

	  void randPopulate(double popDensity);  //makes random grid
    void filePopulate(string fileInput);
    int getRows();
    int getColumns();
    Cell getCell(int row, int col);
    string toString(); //prints grid as a string (access w fileReader class)
    void advanceGen(); //move all Cells forward one generation
    Cell* getNeighbors(int row, int col);  //THIS IS WHAT CHANGES FOR DIFF MODES

  private:
		Cell** gridArray;
		int rows;
		int columns;


};
