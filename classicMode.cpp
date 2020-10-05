#include "ClassicMode.h"
#include <iostream>
#include <fstream>

using namespace std;

//TO DO: change all attempts to access gameGrid like gameGrid[i][j] to
// gameGrid.getCell(i, j)

ClassicMode::ClassicMode(){
  neighbor = 0;
  row = 5;
  column  = 5;
  gameGrid1 = new Grid(row, column);
  gameGrid2 = new Grid(row, column);

}

//constructor
ClassicMode::ClassicMode(int r, int c, Grid gameGrid1){
  // what goes in here idk

  row = r;
  column = c;

  //FIX THIS (maybe make another overloaded constructor in Grid to copy a grid)
  gameGrid2 = new Grid(row, column);
  for(int i = 0; i < row ; i++){
    for(int j = 0; j < column; j++)
      if(gameGrid1.getCell(i, j).toString() == "X")
       gameGrid2->gridArray[i][j] = new Cell(true);
  	}
  }
//destructor
ClassicMode::~ClassicMode(){
  //TO DO: FIX THIS
// delete gameGrid1;
// delete gameGrid2;

}

// runSimulation is just a placeholder don't know what we are calling this yet btw
void ClassicMode::runSimulation(){

  for(int i = 0; i < row; i++){
    for(int j = 0; j < column; j++){
      neighbor = 0;

    // CORNER CELL
      if((i == 0) && (j == 0)){
        if(gameGrid1.getCell(i, j+1).toString() == "X"){
            neighbor++;
          }
          if(gameGrid1[i+1][j].toString() == "X"){

            neighbor++;
          }
          if(gameGrid1[i+1][j+1].toString() == "X"){
            neighbor++;
          }

          // NEW CELL >> gameGrid2
          getGrid(i, j, neighbor);
          neighbor = 0;
        }

      else if((i == 0) && (j == (column - 1))){
        if(gameGrid1[i][j+1].toString() == "X"){
          neighbor++;
        }
        if(gameGrid1[i+1][j].toString() == "X"){
          neighbor++;
        }
        if(gameGrid1[i+1][j-1].toString() == "X"){
          neighbor++;
        }
        // NEW CELL >> gameGrid2
        getGrid(i, j, neighbor);
        neighbor = 0;
      }

      else if((i == (row - 1)) && (j == (column - 1))){
        if(gameGrid1[i][j-1].toString() == "X"){
          neighbor++;
        }
        if(gameGrid1[i-1][j].toString() == "X"){
          neighbor++;
        }
        if(gameGrid1[i-1][j-1].toString() == "X"){
          neighbor++;
        }

        // NEW CELL >> gameGrid2
        getGrid(i, j, neighbor);
        neighbor = 0;

      }
      // CORNER CELL
      else if((i == (row - 1)) && (j == 0)){
        if(gameGrid1[i][j+1].toString() == "X"){
          neighbor++;
        }
        if(gameGrid1[i-1][j].toString() == "X"){
          neighbor++;
        }
        if(gameGrid1[i-1][j+1].toString() == "X"){
          neighbor++;
        }

        // NEW CELL >> gameGrid2
        getGrid(i, j, neighbor);
        neighbor = 0;
      }

      else if((!(i == 0) || (!(i == (row - 2)))) && (j == 0)){
        if(gameGrid1[i-1][j].toString() == "X"){
          neighbor++;
        }
        if(gameGrid1[i-1][j+1].toString() == "X"){
          neighbor++;
        }
        if(gameGrid1[i][j+1].toString() == "X"){
          neighbor++;
        }
        if(gameGrid1[i+1][j+1].toString() == "X"){
          neighbor++;
        }
        if(gameGrid1[i+1][j].toString() == "X"){
          neighbor++;
        }

        // NEW CELL >> gameGrid2
        getGrid(i, j, neighbor);
        neighbor = 0;
      }

      // LOWER COLUMN
      else if((0 < i <= (row - 2)) && (j == (column - 1))){
        if(gameGrid1[i-1][j].toString() == "X"){
          neighbor++;
        }
        if(gameGrid1[i-1][j-1].toString() == "X"){
          neighbor++;
        }
        if(gameGrid1[i][j-1].toString() == "X"){
          neighbor++;
        }
        if(gameGrid1[i+1][j-1].toString() == "X"){
          neighbor++;
        }
        if(gameGrid1[i+1][j].toString() == "X"){
          neighbor++;
        }

        // NEW CELL >> gameGrid2
        getGrid(i, j, neighbor);
        neighbor = 0;
      }

      // UPPER ROW
      else if((i == 0) && (0 < j <= (column - 2))){
        if(gameGrid1[i][j-1].toString() == "X"){
          neighbor++;
        }
        if(gameGrid1[i+1][j-1].toString() == "X"){
          neighbor++;
        }
        if(gameGrid1[i+1][j].toString() == "X"){
          neighbor++;
        }
        if(gameGrid1[i+1][j+1].toString() == "X"){
          neighbor++;
        }
        if(gameGrid1[i][j+1].toString() == "X"){
          neighbor++;
        }

        // NEW CELL >> gameGrid2
        getGrid(i, j, neighbor);
        neighbor = 0;
      }

      // LOWER ROW
      else if((i == (row - 1)) && (0 < j <= (column - 2))){
        if(gameGrid1[i][j-1].toString() == "X"){
          neighbor++;
        }
        if(gameGrid1[i-1][j-1].toString() == "X"){
          neighbor++;
        }
        if(gameGrid1[i-1][j].toString() == "X"){
          neighbor++;
        }
        if(gameGrid1[i-1][j+1].toString() == "X"){
          neighbor++;
        }
        if(gameGrid1[i][j+1].toString() == "X"){
          neighbor++;
        }

        // NEW CELL >> gameGrid2
        getGrid(i, j, neighbor);
        neighbor = 0;
      }

      // MIDDLE CELLS
      else{
        if(gameGrid1[i-1][j-1].toString() == "X"){
          neighbor++;
        }
        if(gameGrid1[i-1][j].toString() == "X"){
          neighbor++;
        }
        if(gameGrid1[i-1][j+1].toString() == "X"){
          neighbor++;
        }
        if(gameGrid1[i][j-1].toString() == "X"){
          neighbor++;
        }
        if(gameGrid1[i][j+1].toString() == "X"){
          neighbor++;
        }
        if(gameGrid1[i+1][j-1].toString() == "X"){
          neighbor++;
        }
        if(gameGrid1[i+1][j].toString() == "X"){
          neighbor++;
        }
        if(gameGrid1[i+1][j+1].toString() == "X"){
          neighbor++;
        }

        // NEW CELL >> gameGrid2
        getGrid(i, j, neighbor);
        neighbor = 0;
      }
    }
  }
}


// checking if game grids are the same
// bool ClassicMode::isEqual(){
//   for(int i = 0; i < row; i++){
//     for(int j = 0; j < column; j++){
//         if (gameGrid1[i][j] != gameGrid2[i][j]){
//             return false;
//         }
//       }
//     }
//   return true;
// }
// }
