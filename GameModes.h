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
    Grid *prevGrid;


  //methods
  public:
    GameModes();
    GameModes(int rows, int columns, double popDensity);
    GameModes(string fileName);
    ~GameModes();
    void playGame(int outChoice);
    void playGame(string fileOutName, int maxGens);
    void fixGrids();
    void getGrid(int i, int j, int nc);
    virtual void advanceGen();



};
#endif
