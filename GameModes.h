#ifndef GAME_MODES_H
#define GAME_MODES_H
#include "Grid.h"


using namespace std;

class GameModes{

  //member variables
protected:
    int neighbor;
    int row;
    int column;

    Grid *gameGrid;
    Grid *tempGrid;


  //methods
  public:
    GameModes();
    ~GameModes();


};
#endif
