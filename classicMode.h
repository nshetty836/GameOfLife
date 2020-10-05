#include <iostream>
#include "Grid.h"

using namespace std;

class ClassicMode{

  //member variables
  private:
    int neighbor;
    int row;
    int column;

  //char *gameGrid1;
  //char *gameGrid2;
    Grid gameGrid1;
    Grid gameGrid2;


  //methods
  public:
    ClassicMode();
    ClassicMode(int row, int column, gameGrid1);
    ~ClassicMode();
    bool isEqual();
    void runSimulation();
    void getGrid(int i, int j, int neighbor);

};
