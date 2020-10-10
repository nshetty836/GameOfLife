#include "MirrorMode.h"
using namespace std;


MirrorMode::MirrorMode(){}

//overloaded constructor for random population
MirrorMode::MirrorMode(int r, int c, float popDensity): super(r, c, popDensity){}

//overloaded constructor for file population
MirrorMode::MirrorMode(string fileName): super(fileName){}

//destructor
MirrorMode::~MirrorMode(){}


void MirrorMode::advanceGen(){

  for(int i = 0; i < row; i++){
    for(int j = 0; j < column; j++){
      neighbor = 0;

    // TOP LEFT CORNER CELL
      if((i == 0) && (j == 0)){
        if(gameGrid->getCell(i, j).getState() == true){
            neighbor+=3;
          }
        if(gameGrid->getCell(i, j+1).getState() == true){
            neighbor+=2;
          }
          if(gameGrid->getCell(i+1,j).getState() == true){
            neighbor+=2;
          }
          if(gameGrid->getCell(i+1,j+1).getState() == true){
            neighbor++;
          }


          // NEW CELL >> tempGrid
          GameModes::getGrid(i, j, neighbor);
          neighbor = 0;
        }

      //TOP RIGHT CORNER
      else if((i == 0) && (j == (column - 1))){
        if(gameGrid->getCell(i, j).getState() == true){
            neighbor+=3;
          }
        if(gameGrid->getCell(i, j-1).getState() == true){
            neighbor+=2;
          }
          if(gameGrid->getCell(i+1,j).getState() == true){
            neighbor+=2;
          }
          if(gameGrid->getCell(i+1,j-1).getState() == true){
            neighbor++;
          }
        // NEW CELL >> tempGrid
        GameModes::getGrid(i, j, neighbor);
        neighbor = 0;
      }

      //BOTTOM RIGHT CORNER
      else if(i == row - 1 && j == column - 1){
        if(gameGrid->getCell(i, j).getState() == true){
            neighbor+=3;
          }
        if(gameGrid->getCell(i, j-1).getState() == true){
            neighbor+=2;
          }
          if(gameGrid->getCell(i-1,j).getState() == true){
            neighbor+=2;
          }
          if(gameGrid->getCell(i-1,j-1).getState() == true){
            neighbor++;
          }

        // NEW CELL >> tempGrid
        GameModes::getGrid(i, j, neighbor);
        neighbor = 0;

      }
      // BOTTOM LEFT CORNER CELL
        else if((i == (row - 1)) && (j == 0)){
          if(gameGrid->getCell(i, j).getState() == true){
              neighbor+=3;
            }
          if(gameGrid->getCell(i, j+1).getState() == true){
              neighbor+=2;
            }
            if(gameGrid->getCell(i-1,j).getState() == true){

              neighbor+=2;
            }
            if(gameGrid->getCell(i-1,j+1).getState() == true){
              neighbor++;
            }

        // NEW CELL >> tempGrid
        GameModes::getGrid(i, j, neighbor);
        neighbor = 0;
      }

      //FIRST COLUMN
      else if((0 < i <= (row - 2)) && (j == 0)){
        if(gameGrid->getCell(i, j).getState() == true){
          neighbor++;
        }
        if(gameGrid->getCell(i-1, j).getState() == true){
          neighbor+=2;
        }
        if(gameGrid->getCell(i-1, j+1).getState() == true){
          neighbor++;
        }
        if(gameGrid->getCell(i, j+1).getState() == true){
          neighbor++;
        }
        if(gameGrid->getCell(i+1, j+1).getState() == true){
          neighbor++;
        }
        if(gameGrid->getCell(i+1, j).getState() == true){
          neighbor+=2;
        }

        // NEW CELL >> tempGrid
        GameModes::getGrid(i, j, neighbor);
        neighbor = 0;
      }

      // LAST COLUMN 
      else if((0 < i <= (row - 2)) && (j == (column - 1))){
        if(gameGrid->getCell(i, j).getState() == true){
            neighbor++;
        }
        if(gameGrid->getCell(i-1, j).getState() == true){
          neighbor+=2;
        }
        if(gameGrid->getCell(i-1, j-1).getState() == true){
          neighbor++;
        }
        if(gameGrid->getCell(i, j-1).getState() == true){
          neighbor++;
        }
        if(gameGrid->getCell(i+1, j-1).getState() == true){
          neighbor++;
        }
        if(gameGrid->getCell(i+1, j).getState() == true){
          neighbor+=2;
        }

        // NEW CELL >> tempGrid
        GameModes::getGrid(i, j, neighbor);
        neighbor = 0;
      }

      // FIRST ROW
      else if((i == 0) && (0 < j <= (column - 2))){
        if(gameGrid->getCell(i, j).getState() == true){
            neighbor++;
        }
        if(gameGrid->getCell(i, j-1).getState() == true){
          neighbor+=2;
        }
        if(gameGrid->getCell(i+1, j-1).getState() == true){
          neighbor++;
        }
        if(gameGrid->getCell(i+1, j).getState() == true){
          neighbor++;
        }
        if(gameGrid->getCell(i+1, j+1).getState() == true){
          neighbor++;
        }
        if(gameGrid->getCell(i, j+1).getState() == true){
          neighbor+=2;
        }

        // NEW CELL >> tempGrid
        GameModes::getGrid(i, j, neighbor);
        neighbor = 0;
      }

      // LAST ROW
      else if((i == (row - 1)) && (0 < j && j <= (column - 2))){
        if(gameGrid->getCell(i, j).getState() == true){
            neighbor++;
        }
        if(gameGrid->getCell(i, j-1).getState() == true){
          neighbor+=2;
        }
        if(gameGrid->getCell(i-1, j-1).getState() == true){
          neighbor++;
        }
        if(gameGrid->getCell(i-1, j).getState() == true){
          neighbor++;
        }
        if(gameGrid->getCell(i-1, j+1).getState() == true){
          neighbor++;
        }
        if(gameGrid->getCell(i, j+1).getState() == true){
          neighbor+=2;
        }


        // NEW CELL >> tempGrid
        GameModes::getGrid(i, j, neighbor);
        neighbor = 0;
      }

      // MIDDLE CELLS
      else{
        if(gameGrid->getCell(i-1, j-1).getState() == true){
          neighbor++;
        }
        if(gameGrid->getCell(i-1, j).getState() == true){
          neighbor++;
        }
        if(gameGrid->getCell(i-1, j+1).getState() == true){
          neighbor++;
        }
        if(gameGrid->getCell(i, j-1).getState() == true){
          neighbor++;
        }
        if(gameGrid->getCell(i, j+1).getState() == true){
          neighbor++;
        }
        if(gameGrid->getCell(i+1, j-1).getState() == true){
          neighbor++;
        }
        if(gameGrid->getCell(i+1, j).getState() == true){
          neighbor++;
        }
        if(gameGrid->getCell(i+1, j+1).getState() == true){
          neighbor++;
        }

        // NEW CELL >> tempGrid
        GameModes::getGrid(i, j, neighbor);
        neighbor = 0;

      }
    }
  }
}


// bool MirrorMode::checkIfEqual(){
//   return tempGrid->equals(gameGrid);
// }
//
// string MirrorMode::toString(){
//   return gameGrid->toString();
// }
