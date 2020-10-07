#include <iostream>
#include "Grid.h"
using namespace std;

class MirrorMode{

  private:
    int neighbor;
    int row;
    int column;

    Grid *gameGrid;
    Grid *tempGrid;

  public:
    MirrorMode();
    MirrorMode(int row, int column, Grid gameGrid);
    MirrorMode(string fileName);
    ~MirrorMode();
    void advanceGen();
    void getGrid(int i, int j, int neighbor);
    string toString();
    bool isEqual();
};
