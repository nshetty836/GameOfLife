#include <iostream>
#include "Grid.h"

using namespace std;

class ClassicMode{

  //member variables
  private:
    int neighbor;
    int row;
    int column;

    Grid *gameGrid;
    Grid *tempGrid;


  //methods
  public:
    ClassicMode();
    ClassicMode(int row, int column, Grid gameGrid);
    ClassicMode(string fileName);
    ~ClassicMode();
    bool isEqual();
    void advanceGen();
    bool checkIfEqual();
    void getGrid(int i, int j, int neighbor);
    string toString();

};
