#include "classicMode.h"
#include <iostream>
#include <fstream>

using namespace std;

classicMode::classicMode(){
  neighbor = 0; 
  row = 0;
  column  = 0;
}

//constructor
classicMode::classicMode(int row, int column){
  // what goes in here idk 
  	}
}

//destructor
classicMode::~classicMode(){
delete gameGrid1;
delete gameGrid2;

}
// runSimulation is just a placeholder don't know what we are calling this yet btw
void classicMode::runSimulation(){

  for(int i = 0; i < row; i++){
    for(int j = 0; j < column; j++){
      neighbor = 0;

    // CORNER CELL
      if((i == 0) && (j == 0)){
        if(gameGrid1[i][j+1].toString() == “X”){
            neighbor++;
          }
          if(gameGrid1[i+1][j].toString() == “X”){

            neighbor++;
          }
          if(gameGrid1[i+1][j+1].toString() == “X”){
            neighbor++;
          }

          // NEW CELL >> gameGrid2
          getGrid(i, j, neighbor);
          neighbor = 0;
        }

      else if((i == 0) && (j == (column - 1))){
        if(gameGrid1[i][j+1].toString() == “X”){
          neighbor++;
        }
        if(gameGrid1[i+1][j].toString() == “X”'){
          neighbor++;
        }
        if(gameGrid1[i+1][j-1].toString() == “X”){
          neighbor++;
        }
        // NEW CELL >> gameGrid2
        getGrid(i, j, neighbor);
        neighbor = 0;
      }
      
      else if((i == (row - 1)) && (j == (column - 1))){
        if(gameGrid1[i][j-1].toString() == “X”){
          neighbor++;
        }
        if(gameGrid1[i-1][j].toString() == “X”'){
          neighbor++;
        }
        if(gameGrid1[i-1][j-1].toString() == “X”){
          neighbor++;
        }

        // NEW CELL >> gameGrid2 
        getGrid(i, j, neighbor);
        neighbor = 0;

      }
      // CORNER CELL
      else if((i == (row - 1)) && (j == 0)){
        if(gameGrid1[i][j+1].toString() == “X”){
          neighbor++;
        }
        if(gameGrid1[i-1][j].toString() == “X”){
          neighbor++;
        }
        if(gameGrid1[i-1][j+1].toString() == “X”){
          neighbor++;
        }

        // NEW CELL >> gameGrid2 
        getGrid(i, j, neighbor);
        neighbor = 0;
      }
      
      else if((!(i == 0) || (!(i == (row - 2)))) && (j == 0)){
        if(gameGrid1[i-1][j].toString() == “X”){
          neighbor++;
        }
        if(gameGrid1[i-1][j+1].toString() == “X”){
          neighbor++;
        }
        if(gameGrid1[i][j+1].toString() == “X”){
          neighbor++;
        }
        if(gameGrid1[i+1][j+1].toString() == “X”){
          neighbor++;
        }
        if(gameGrid1[i+1][j].toString() == “X”){
          neighbor++;
        }

        // NEW CELL >> gameGrid2 
        getGrid(i, j, neighbor);
        neighbor = 0;
      }
      
      // LOWER COLUMN
      else if((0 < i <= (row - 2)) && (j == (column - 1))){
        if(gameGrid1[i-1][j].toString() == “X”){
          neighbor++;
        }
        if(gameGrid1[i-1][j-1].toString() == “X”){
          neighbor++;
        }
        if(gameGrid1[i][j-1].toString() == “X”){
          neighbor++;
        }
        if(gameGrid1[i+1][j-1].toString() == “X”){
          neighbor++;
        }
        if(gameGrid1[i+1][j].toString() == “X”){
          neighbor++;
        }

        // NEW CELL >> gameGrid2 
        getGrid(i, j, neighbor);
        neighbor = 0;
      }
      
      // UPPER ROW
      else if((i == 0) && (0 < j <= (column - 2))){
        if(gameGrid1[i][j-1].toString() == “X”){
          neighbor++;
        }
        if(gameGrid1[i+1][j-1].toString() == “X”){
          neighbor++;
        }
        if(gameGrid1[i+1][j].toString() == “X”){
          neighbor++;
        }
        if(gameGrid1[i+1][j+1].toString() == “X”){
          neighbor++;
        }
        if(gameGrid1[i][j+1].toString() == “X”){
          neighbor++;
        }

        // NEW CELL >> gameGrid2 
        getGrid(i, j, neighbor);
        neighbor = 0;
      }
      
      // LOWER ROW
      else if((i == (row - 1)) && (0 < j <= (column - 2))){
        if(gameGrid1[i][j-1].toString() == “X”){
          neighbor++;
        }
        if(gameGrid1[i-1][j-1].toString() == “X”){
          neighbor++;
        }
        if(gameGrid1[i-1][j].toString() == “X”){
          neighbor++;
        }
        if(gameGrid1[i-1][j+1].toString() == “X”){
          neighbor++;
        }
        if(gameGrid1[i][j+1].toString() == “X”){
          neighbor++;
        }

        // NEW CELL >> gameGrid2 
        getGrid(i, j, neighbor);
        neighbor = 0;
      }
      
      // MIDDLE CELLS 
      else{
        if(gameGrid1[i-1][j-1].toString() == “X”){
          neighbor++;
        }
        if(gameGrid1[i-1][j].toString() == “X”){
          neighbor++;
        }
        if(gameGrid1[i-1][j+1].toString() == “X”){
          neighbor++;
        }
        if(gameGrid1[i][j-1].toString() == “X”){
          neighbor++;
        }
        if(gameGrid1[i][j+1].toString() == “X”){
          neighbor++;
        }
        if(gameGrid1[i+1][j-1].toString() == “X”){
          neighbor++;
        }
        if(gameGrid1[i+1][j].toString() == “X”){
          neighbor++;
        }
        if(gameGrid1[i+1][j+1].toString() == “X”){
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
bool classicMode::isEqual(){
  for(int i = 0; i < row; i++){
    for(int j = 0; j < column; j++){
        if (gameGrid1[i][j] != gameGrid2[i][j]){
            return false;
        }
      }
    }
  return true;
}
