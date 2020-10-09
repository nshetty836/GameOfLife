#include <iostream>
#include "GameModes.h"
using namespace std;

class ClassicMode : public GameModes{

  //methods
  public:
    ClassicMode();
    ClassicMode(int r, int c, double popDensity);
    ClassicMode(string fileName);
    ~ClassicMode();
    bool isEqual();
    void advanceGen();
    bool checkIfEqual();
    string toString();
    typedef GameModes super; //Initialized super to call from inherited class GameModes


};
