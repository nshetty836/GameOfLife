#include "GameModes.h"
using namespace std;

class MirrorMode : public GameModes{

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
