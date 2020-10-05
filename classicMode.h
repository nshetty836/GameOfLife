#include <iostream>
#include "Grid.h"

using namespace std;

class ClassicMode{

  //member variables
  private:
    int neighbor;
    int row;
    int column;

    Grid *gameGrid1;
    Grid *gameGrid2;


  //methods
  public:
    ClassicMode();
    ClassicMode(int row, int column, Grid gameGrid1);
    ~ClassicMode();
    bool isEqual();
    void runSimulation();
    void getGrid(int i, int j, int neighbor);

};
