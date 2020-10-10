#include <iostream>
#include "GameModes.h"
using namespace std;

class DonutMode : public GameModes{

  public:
    DonutMode();
    DonutMode(int row, int column, float popDensity);
    DonutMode(string fileName);
    ~DonutMode();
    void advanceGen();
    string toString();
    bool isEqual();
    typedef GameModes super; //Initialized super to call from inherited class GameModes

};
