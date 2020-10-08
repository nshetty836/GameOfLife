#include <iostream>
#include "Grid.h"
using namespace std;

class DonutMode{

  private:
    int neighbor;
    int row;
    int column;

    Grid *gameGrid;
    Grid *tempGrid;

  public:
    DonutMode();
    DonutMode(int row, int column, Grid gameGrid);
    DonutMode(string fileName);
    ~DonutMode();
    void advanceGen();
    void getGrid(int i, int j, int neighbor);
    string toString();
    bool isEqual();
};
