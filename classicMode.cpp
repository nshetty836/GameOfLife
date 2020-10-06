#include "ClassicMode.h"
//#include "Grid.h"
#include <iostream>
#include <fstream>

using namespace std;

//TO DO: change all attempts to access gameGrid like gameGrid[i][j] to
// gameGrid.getCell(i, j)

ClassicMode::ClassicMode(){
  neighbor = 0;
  row = 5;
  column  = 5;
  gameGrid = new Grid(row, column);
  tempGrid = new Grid(row, column);

}

//constructor
ClassicMode::ClassicMode(int r, int c, Grid gameGrid){

  row = r;
  column = c;

  //FIX THIS (maybe make another overloaded constructor in Grid to copy a grid)
  tempGrid = new Grid(row, column);
  for(int i = 0; i < row ; i++){
    for(int j = 0; j < column; j++)
      if(gameGrid.getCell(i, j).toString() == "X")
       tempGrid->gridArray[i][j] = new Cell(true);
  	}
  }

ClassicMode::ClassicMode(string fileName){

  gameGrid = new Grid(fileName);
  row = gameGrid->getRows();
  column = gameGrid->getColumns();

  //FIX THIS (maybe make another overloaded constructor in Grid to copy a grid)
  tempGrid = new Grid(row, column);

  for(int i = 0; i < row ; i++){
    for(int j = 0; j < column; j++)
      if(gameGrid->getCell(i, j).toString() == "X")
       tempGrid->gridArray[i][j] = new Cell(true);
  	}
  }
//destructor
ClassicMode::~ClassicMode(){
  //TO DO: FIX THIS
// delete gameGrid;
// delete tempGrid;

}

void ClassicMode::getGrid(int i, int j, int nc){
    if(nc == 3){
      tempGrid->getCell(i,j).setAlive();
    }
    //one or less neighbors = death
    else if(nc == 0){
      tempGrid->getCell(i,j).setDead();
    }
    //one or less neighbors = death
    else if(nc == 1){
    tempGrid->getCell(i,j).setDead();
    }
    //two neighbors = no change / stable
    else if(nc == 2){
      tempGrid->getCell(i,j) = gameGrid->getCell(i,j);
    }
    // 4+ neighbors = death
    else if(nc == 4){
    tempGrid->getCell(i,j).setDead();
    }
    else{
      tempGrid->getCell(i,j).setDead();
    }
}

void ClassicMode::runSimulation(){

  for(int i = 0; i < row; i++){
    for(int j = 0; j < column; j++){
      neighbor = 0;

    // CORNER CELL
      if((i == 0) && (j == 0)){
        if(gameGrid->getCell(i, j+1).toString() == "X"){
            neighbor++;
          }
          if(gameGrid->getCell(i+1,j).toString() == "X"){

            neighbor++;
          }
          if(gameGrid->getCell(i+1,j+1).toString() == "X"){
            neighbor++;
          }

          // NEW CELL >> tempGrid
          getGrid(i, j, neighbor);
          neighbor = 0;
        }

      else if((i == 0) && (j == (column - 1))){
        if(gameGrid->getCell(i, j+1).toString() == "X"){
            neighbor++;
          }
          if(gameGrid->getCell(i+1,j).toString() == "X"){

            neighbor++;
          }
          if(gameGrid->getCell(i+1,j-1).toString() == "X"){
            neighbor++;
          }
        // NEW CELL >> tempGrid
        getGrid(i, j, neighbor);
        neighbor = 0;
      }

      else if((i == (row - 1)) && (j == (column - 1))){
        if(gameGrid->getCell(i, j-1).toString() == "X"){
            neighbor++;
          }
          if(gameGrid->getCell(i-1,j).toString() == "X"){

            neighbor++;
          }
          if(gameGrid->getCell(i-1,j-1).toString() == "X"){
            neighbor++;
          }

        // NEW CELL >> tempGrid
        getGrid(i, j, neighbor);
        neighbor = 0;

      }
      // CORNER CELL

        else if((i == (row - 1)) && (j == 0)){
          if(gameGrid->getCell(i, j+1).toString() == "X"){
              neighbor++;
            }
            if(gameGrid->getCell(i-1,j).toString() == "X"){

              neighbor++;
            }
            if(gameGrid->getCell(i-1,j+1).toString() == "X"){
              neighbor++;
            }

        // NEW CELL >> tempGrid
        getGrid(i, j, neighbor);
        neighbor = 0;
      }

      else if((!(i == 0) || (!(i == (row - 2)))) && (j == 0)){
        if(gameGrid->getCell(i-1, j).toString() == "X"){
          neighbor++;
        }
        if(gameGrid->getCell(i-1, j+1).toString() == "X"){
          neighbor++;
        }
        if(gameGrid->getCell(i, j+1).toString() == "X"){
          neighbor++;
        }
        if(gameGrid->getCell(i+1, j+1).toString() == "X"){
          neighbor++;
        }
        if(gameGrid->getCell(i+1, j).toString() == "X"){
          neighbor++;
        }

        // NEW CELL >> tempGrid
        getGrid(i, j, neighbor);
        neighbor = 0;
      }

      // LOWER COLUMN
      else if((0 < i <= (row - 2)) && (j == (column - 1))){
        if(gameGrid->getCell(i-1, j).toString() == "X"){
          neighbor++;
        }
        if(gameGrid->getCell(i-1, j-1).toString() == "X"){
          neighbor++;
        }
        if(gameGrid->getCell(i, j-1).toString() == "X"){
          neighbor++;
        }
        if(gameGrid->getCell(i+1, j-1).toString() == "X"){
          neighbor++;
        }
        if(gameGrid->getCell(i+1, j).toString() == "X"){
          neighbor++;
        }

        // NEW CELL >> tempGrid
        getGrid(i, j, neighbor);
        neighbor = 0;
      }

      // UPPER ROW
      else if((i == 0) && (0 < j <= (column - 2))){
        if(gameGrid->getCell(i, j-1).toString() == "X"){
          neighbor++;
        }
        if(gameGrid->getCell(i+1, j-1).toString() == "X"){
          neighbor++;
        }
        if(gameGrid->getCell(i+1, j).toString() == "X"){
          neighbor++;
        }
        if(gameGrid->getCell(i+1, j-1).toString() == "X"){
          neighbor++;
        }
        if(gameGrid->getCell(i, j+1).toString() == "X"){
          neighbor++;
        }

        // NEW CELL >> tempGrid
        getGrid(i, j, neighbor);
        neighbor = 0;
      }

      // LOWER ROW
      else if((i == (row - 1)) && (0 < j <= (column - 2))){
        if(gameGrid->getCell(i, j-1).toString() == "X"){
          neighbor++;
        }
        if(gameGrid->getCell(i-1, j-1).toString() == "X"){
          neighbor++;
        }
        if(gameGrid->getCell(i-1, j).toString() == "X"){
          neighbor++;
        }
        if(gameGrid->getCell(i-1, j+1).toString() == "X"){
          neighbor++;
        }
        if(gameGrid->getCell(i, j+1).toString() == "X"){
          neighbor++;
        }

        // NEW CELL >> tempGrid
        getGrid(i, j, neighbor);
        neighbor = 0;
      }

      // MIDDLE CELLS
      else{
        if(gameGrid->getCell(i-1, j-1).toString() == "X"){
          neighbor++;
        }
        if(gameGrid->getCell(i-1, j).toString() == "X"){
          neighbor++;
        }
        if(gameGrid->getCell(i-1, j+1).toString() == "X"){
          neighbor++;
        }
        if(gameGrid->getCell(i, j-1).toString() == "X"){
          neighbor++;
        }
        if(gameGrid->getCell(i, j+1).toString() == "X"){
          neighbor++;
        }
        if(gameGrid->getCell(i+1, j-1).toString() == "X"){
          neighbor++;
        }
        if(gameGrid->getCell(i+1, j).toString() == "X"){
          neighbor++;
        }
        if(gameGrid->getCell(i+1, j+1).toString() == "X"){
          neighbor++;
        }

        // NEW CELL >> tempGrid
        getGrid(i, j, neighbor);
        neighbor = 0;
      }
    }
  }
}

string ClassicMode::toString(){
  return tempGrid->toString();
}


//checking if game grids are the same
// bool ClassicMode::isEqual(){
//   for(int i = 0; i < row; i++){
//     for(int j = 0; j < column; j++){
//         if (gameGrid[i][j] != tempGrid[i][j]){
//             return false;
//         }
//       }
//     }
//   return true;
// }
// }
