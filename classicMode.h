#include <iostream>

using namespace std;

class ClassicMode{

  //member variables
  private:
    int neighbor;
    int row;
    int column;

    char *gameGrid1;
    char *gameGrid2;
    
  //methods
  public:
    ClassicMode();
    ClassicMode(int row, int column, gameGrid1);
    ~ClassicMode();
    bool isEqual();
};
