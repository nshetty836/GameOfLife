#include "ClassicMode.h"
using namespace std;


ClassicMode::ClassicMode(){}

//overloaded constructor for random population
ClassicMode::ClassicMode(int r, int c, double popDensity): super(r, c, popDensity){}

//overloaded constructor for file population
ClassicMode::ClassicMode(string fileName): super(fileName){}

//destructor
ClassicMode::~ClassicMode(){}


void ClassicMode::advanceGen(){

  for(int i = 0; i < row; i++){
    for(int j = 0; j < column; j++){
      neighbor = 0;

    // CORNER CELL
      if((i == 0) && (j == 0)){
        if(gameGrid->getCell(i, j+1).getState() == true){
            neighbor++;
          }
          if(gameGrid->getCell(i+1,j).getState() == true){
            neighbor++;
          }
          if(gameGrid->getCell(i+1,j+1).getState() == true){
            neighbor++;
          }


          // NEW CELL >> tempGrid
          GameModes::getGrid(i, j, neighbor);
          neighbor = 0;
        }

      else if((i == 0) && (j == (column - 1))){
        if(gameGrid->getCell(i, j+1).getState() == true){
            neighbor++;
          }
          if(gameGrid->getCell(i+1,j).getState() == true){
            neighbor++;
          }
          if(gameGrid->getCell(i+1,j-1).getState() == true){
            neighbor++;
          }
        // NEW CELL >> tempGrid
        GameModes::getGrid(i, j, neighbor);
        neighbor = 0;
      }

      else if((i == (row - 1)) && (j == (column - 1))){
        if(gameGrid->getCell(i, j-1).getState() == true){
            neighbor++;
          }
          if(gameGrid->getCell(i-1,j).getState() == true){
            neighbor++;
          }
          if(gameGrid->getCell(i-1,j-1).getState() == true){
            neighbor++;
          }

        // NEW CELL >> tempGrid
        GameModes::getGrid(i, j, neighbor);
        neighbor = 0;

      }
      // CORNER CELL
        else if((i == (row - 1)) && (j == 0)){
          if(gameGrid->getCell(i, j+1).getState() == true){
              neighbor++;
            }
            if(gameGrid->getCell(i-1,j).getState() == true){

              neighbor++;
            }
            if(gameGrid->getCell(i-1,j+1).getState() == true){
              neighbor++;
            }

        // NEW CELL >> tempGrid
        GameModes::getGrid(i, j, neighbor);
        neighbor = 0;
      }

      else if((!(i == 0) || (!(i == (row - 2)))) && (j == 0)){
        if(gameGrid->getCell(i-1, j).getState() == true){
          neighbor++;
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
          neighbor++;
        }

        // NEW CELL >> tempGrid
        GameModes::getGrid(i, j, neighbor);
        neighbor = 0;
      }

      // LOWER COLUMN
      else if((0 < i <= (row - 2)) && (j == (column - 1))){
        if(gameGrid->getCell(i-1, j).getState() == true){
          neighbor++;
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
          neighbor++;
        }

        // NEW CELL >> tempGrid
        GameModes::getGrid(i, j, neighbor);
        neighbor = 0;
      }

      // UPPER ROW
      else if((i == 0) && (0 < j && j <= (column - 2))){
        if(gameGrid->getCell(i, j-1).getState() == true){
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
        if(gameGrid->getCell(i, j+1).getState() == true){
          neighbor++;
        }

        // NEW CELL >> tempGrid
        GameModes::getGrid(i, j, neighbor);
        neighbor = 0;
      }

      // LOWER ROW
      else if((i == (row - 1)) && (0 < j && j <= (column - 2))){
        if(gameGrid->getCell(i, j-1).getState() == true){
          neighbor++;
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
          neighbor++;
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


// bool ClassicMode::checkIfEqual(){
//   return tempGrid->equals(gameGrid);
// }
//
// string ClassicMode::toString(){
//   return gameGrid->toString();
// }
