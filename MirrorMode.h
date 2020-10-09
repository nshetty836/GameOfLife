#include "GameModes.h"
using namespace std;

class MirrorMode : public GameModes{

  public:
    MirrorMode();
    MirrorMode(int row, int column, double popDensity);
    MirrorMode(string fileName);
    ~MirrorMode();
    void advanceGen();
    string toString();
    typedef GameModes super; //Initialized super to call from inherited class GameModes
};
