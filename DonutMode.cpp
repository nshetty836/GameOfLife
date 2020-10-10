#include "DonutMode.h"
#include <iostream>
#include <fstream>

using namespace std;
//default constructor
DonutMode::DonutMode(){}

//constructor
DonutMode::DonutMode(int r, int c, float popDensity): super(r, c, popDensity){}

DonutMode::DonutMode(string fileName): super(fileName){}

//destructor
DonutMode::~DonutMode(){}

void DonutMode::advanceGen(){
  for(int i = 0; i < row; i++){
    for(int j = 0; j < column; j++){
      neighbor = 0;

      // TOP LEFT CORNER CELL
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
        // NEW CELL >> nextGrid
        getGrid(i, j, neighbor);
        neighbor = 0;
      }
      //TOP RIGHT CORNER CELL
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
        if(gameGrid->getCell(i+(row-1),j).getState() == true){
          neighbor++;
        }
        if(gameGrid->getCell(i+(row-1),j-1).getState() == true){
          neighbor++;
        }
        if(gameGrid->getCell(i+(row-1), 0).getState() == true){
          neighbor++;
        }
        if(gameGrid->getCell(i, 0).getState() == true){
          neighbor++;
        }

        if(gameGrid->getCell(i+1, 0).getState() == true){
          neighbor++;
        }
        // NEW CELL >> nextGrid
        getGrid(i, j, neighbor);
        neighbor = 0;
      }
      // BOTTOM RIGHT CORNER CELL
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
          if(gameGrid->getCell(0,j).getState() == true){
            neighbor++;
          }
          if(gameGrid->getCell(0,j- 1).getState() == true){
            neighbor++;
          }
          if(gameGrid->getCell(0,0).getState() == true){
            neighbor++;
          }
          if(gameGrid->getCell(i,0).getState() == true){
            neighbor++;
          }
          if(gameGrid->getCell(i-1, 0).getState() == true){
            neighbor++;
          }
          // NEW CELL >> nextGrid
          getGrid(i, j, neighbor);
          neighbor = 0;
      }
      // BOTTOM LEFT CORNER CELL
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
        if(gameGrid->getCell(0,0).getState() == true){
          neighbor++;
        }
        if(gameGrid->getCell(0,j+1).getState() == true){
          neighbor++;
        }
        if(gameGrid->getCell(0,j+(column - 1)).getState() == true){
          neighbor++;
        }
        if(gameGrid->getCell(i,j+(column - 1)).getState() == true){
          neighbor++;
        }
        if(gameGrid->getCell(i-1,j+(column-1)).getState() == true){
          neighbor++;
        }
        // NEW CELL >> nextGrid
        getGrid(i, j, neighbor);
        neighbor = 0;
      }
      // FIRST COLUMN
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
        // NEW CELL >> nextGrid
        getGrid(i, j, neighbor);
        neighbor = 0;
      }
      // LAST COLUMN
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
        if(gameGrid->getCell(i, 0).getState() == true){
          neighbor++;
        }
        if(gameGrid->getCell(i-1, 0).getState() == true){
          neighbor++;
        }
        if(gameGrid->getCell(i+1, 0).getState() == true){
          neighbor++;
        }
        // NEW CELL >> nextGrid
        getGrid(i, j, neighbor);
        neighbor = 0;
      }
      // UPPER ROW - FIRST ROW
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
        // NEW CELL >> nextGrid
        getGrid(i, j, neighbor);
        neighbor = 0;
      }
      // LOWER ROW - LAST ROW
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

        if(gameGrid->getCell(0, j).getState() == true){
          neighbor++;
        }
        if(gameGrid->getCell(0, j-1).getState() == true){
          neighbor++;
        }
        if(gameGrid->getCell(0, j+1).getState() == true){
          neighbor++;
        }
        // NEW CELL >> nextGrid
        getGrid(i, j, neighbor);
        neighbor = 0;
      }
      // MIDDLE CELL
      // REMAINING CELLS
      // NO CORNERS
      // NO EDGES
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
        // NEW CELL >> nextGrid
        getGrid(i, j, neighbor);
        neighbor = 0;
      }
    }
  }
}
