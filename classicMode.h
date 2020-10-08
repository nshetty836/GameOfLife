#include <iostream>
// #ifndef GAME_MODES_H
// #define GAME_MODES_H
#include "GameModes.h"
using namespace std;

class ClassicMode : public GameModes{

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
// #endif
