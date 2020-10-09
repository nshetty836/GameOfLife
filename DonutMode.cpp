#include "DonutMode.h"
#include <iostream>
#include <fstream>


using namespace std;

//default constructor
DonutMode::DonutMode(){}

//constructor
DonutMode::DonutMode(int r, int c, double popDensity): super(r, c, popDensity){}

DonutMode::DonutMode(string fileName): super(fileName){}

//destructor
DonutMode::~DonutMode(){}

//Making the new board, logic of the game
void DonutMode::advanceGen(){
  //for loop to iterate through the array
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
        if(gameGrid->getCell(i,j+(column-1)).getState() == true){
          neighbor++;
        }
        if(gameGrid->getCell(i+1,j+(column-1)).getState() == true){
          neighbor++;
        }
        if(gameGrid->getCell(i + (row-1),j+(column - 1)).getState() == true){
          neighbor++;
        }
        if(gameGrid->getCell(i + (row-1),j).getState() == true){
          neighbor++;
        }
        if(gameGrid->getCell(i + (row-1),j+1) .getState() == true){
          neighbor++;
        }
        // NEW CELL >> tempGrid
        getGrid(i, j, neighbor);
        neighbor = 0;
      }
      // CORNER CELL
      else if((i == 0) && (j == (column - 1))){
        if(gameGrid->getCell(i, j-1).getState() == true){
          neighbor++;
        }
        if(gameGrid->getCell(i+1,j-1).getState() == true){
          neighbor++;
        }
        if(gameGrid->getCell(i+1,j).getState() == true){
          neighbor++;
        }
        if(gameGrid->getCell(i + (row-1),j).getState() == true){
          neighbor++;
        }
        if(gameGrid->getCell(i + (row-1),j-1).getState() == true){
          neighbor++;
        }

        if(gameGrid->gridArray[i + (row-1)][0].getState() == true){
          neighbor++;
        }
        if(gameGrid->gridArray[i][0].getState() == true){
          neighbor++;
        }

        if(gameGrid->gridArray[i+1][0].getState() == true){
          neighbor++;
        }

        // NEW CELL >> tempGrid
        getGrid(i, j, neighbor);
        neighbor = 0;

      }
      // CORNER CELL
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
          if(gameGrid->gridArray[0][j].getState() == true){
            neighbor++;
          }
          if(gameGrid->gridArray[0][j-1].getState() == true){
            neighbor++;
          }
          if(gameGrid->gridArray[0][0].getState() == true){
            neighbor++;
          }
          if(gameGrid->gridArray[i][0].getState() == true){
            neighbor++;
          }
          if(gameGrid->gridArray[i-1][0].getState() == true){
            neighbor++;
          }

          // NEW CELL >> tempGrid
          getGrid(i, j, neighbor);
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
        if(gameGrid->gridArray[0][0].getState() == true){
          neighbor++;
        }
        if(gameGrid->gridArray[0][j+1].getState() == true){
          neighbor++;
        }
        if(gameGrid->gridArray[0][j+(column - 1)].getState() == true){
          neighbor++;
        }
        if(gameGrid->getCell(i,j+(column - 1)).getState() == true){
          neighbor++;
        }
        if(gameGrid->getCell(i-1,j+(column-1)).getState() == true){
          neighbor++;
        }

        // NEW CELL >> tempGrid
        getGrid(i, j, neighbor);
        neighbor = 0;
      }
      //UPPER COLUMN
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
        if(gameGrid->getCell(i, j+(column-1)).getState() == true){
          neighbor++;
        }
        if(gameGrid->getCell(i-1, j+(column-1)).getState() == true){
          neighbor++;
        }
        if(gameGrid->getCell(i+1, j+(column-1)).getState() == true){
          neighbor++;
        }

        // NEW CELL >> tempGrid
        getGrid(i, j, neighbor);
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
        if(gameGrid->gridArray[i][0].getState() == true){
          neighbor++;
        }
        if(gameGrid->gridArray[i-1][0].getState() == true){
          neighbor++;
        }
        if(gameGrid->gridArray[i+1][0].getState() == true){
          neighbor++;
        }

        // NEW CELL >> tempGrid
        getGrid(i, j, neighbor);
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
        if(gameGrid->getCell(i, j+1).getState() == true) {
          neighbor++;
        }
        if(gameGrid->getCell(i+(row - 1), j).getState() == true){
          neighbor++;
        }
        if(gameGrid->getCell(i+(row - 1), j-1).getState() == true){
          neighbor++;
        }
        if(gameGrid->getCell(i+(row - 1), j+1).getState() == true){
          neighbor++;
        }

        // NEW CELL >> tempGrid
        getGrid(i, j, neighbor);
        neighbor = 0;
      }
      // LOWER ROW
      else if((i == (row - 1)) && (0 < j <= (column - 2))){
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

        if(gameGrid->gridArray[0][j].getState() == true){
          neighbor++;
        }
        if(gameGrid->gridArray[0][j-1].getState() == true){
          neighbor++;
        }
        if(gameGrid->gridArray[0][j+1].getState() == true){
          neighbor++;
        }
        // NEW CELL >> tempGrid
        getGrid(i, j, neighbor);
        neighbor = 0;
      }
      // MIDDLE CELL
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
        getGrid(i, j, neighbor);
        neighbor = 0;
      }
    }
  }
}


string DonutMode::toString(){
  return gameGrid->toString();
}
