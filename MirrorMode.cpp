#include <iostream>
#include <fstream>
#include <unistd.h>
#include "MirrorMode.h"
#include "GameModes.h"
using namespace std;

MirrorMode::MirrorMode(){}

MirrorMode::MirrorMode(int r, int c, double popDensity): super(r, c, popDensity){}

MirrorMode::MirrorMode(string fileName): super(fileName){}

//destructor
MirrorMode::~MirrorMode(){}

void MirrorMode::advanceGen(){
  for(int i = 0; i < row; i++){
    for(int j = 0; j < column; j++){
      neighbor = 0;

      //CORNER CELL
      // TOP LEFT
      if((i == 0) && (j == 0)){
          if(gameGrid->getCell(i,j).getState() == true){
            neighbor+= 3;
        }
          if(gameGrid->getCell(i, j+1).getState() == true){
            neighbor+= 2;
        }
          if(gameGrid->getCell(i+1,j).getState() == true){
            neighbor+=2;
        }
          if(gameGrid->getCell(i+1,j+1).getState() == true){
            neighbor++;
        }
        // NEW CELL >> tempGrid
        getGrid(i, j, neighbor);
        neighbor = 0;
      }
      //CORNER CELL
      // TOP RIGHT
      else if((i == 0) && (j == (column - 1))){
          if(gameGrid->getCell(i, j).getState() == true){
            neighbor+= 3;
        }
          if(gameGrid->getCell(i, j-1).getState() == true){
            neighbor+= 2;
        }
          if(gameGrid->getCell(i+1,j-1).getState() == true){
            neighbor+= 2;
        }
          if(gameGrid->getCell(i+1,j).getState() == true){
            neighbor++;
        }
        // cout << neighbor << endl;
        // NEW CELL >> tempGrid
        getGrid(i, j, neighbor);
        neighbor = 0;
      }
      // CORNER CELL
      // BOTTOM RIGHT
      else if((i == (row - 1)) && (j == (column - 1))){
          if(gameGrid->getCell(i, j).getState() == true){
            neighbor+= 3;
        }
          if(gameGrid->getCell(i, j-1).getState() == true){
            neighbor+= 2;
        }
          if(gameGrid->getCell(i-1,j).getState() == true){
            neighbor+= 2;
        }
          if(gameGrid->getCell(i-1,j-1).getState() == true){
            neighbor++;
        }
        // NEW CELL >> tempGrid
        getGrid(i, j, neighbor);
        neighbor = 0;
      }
      // CORNER CELL
      // BOTTOM LEFT
      else if((i == (row - 1)) && (j == 0)){
          if(gameGrid->getCell(i, j).getState() == true){
            neighbor+= 3;
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
        getGrid(i, j, neighbor);
        neighbor = 0;
      }
      // UPPER COLUMN
      // FIRST COLUMN
      else if((!(i == 0) || (!(i == (row - 2)))) && (j == 0)){
          if(gameGrid->getCell(i, j).getState() == true){
            neighbor++;
        }
          if(gameGrid->getCell(i-1, j).getState() == true){
            neighbor+= 2;
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
            neighbor+= 2;
        }

        // NEW CELL >> tempGrid
        getGrid(i, j, neighbor);
        neighbor = 0;
      }
      // LOWER COLUMN
      // LAST COLUMN
      else if((0 < i <= (row - 2)) && (j == (column - 1))){
          if(gameGrid->getCell(i, j).getState() == true){
            neighbor++;
        }
          if(gameGrid->getCell(i-1, j).getState() == true){
            neighbor+= 2;
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
            neighbor+= 2;
        }
        // NEW CELL >> tempGrid
        getGrid(i, j, neighbor);
        neighbor = 0;
      }
        // UPPER ROW
        // FIRST ROW
        else if((i == 0) && (0 < j && j <= (column - 2))){
          if(gameGrid->getCell(i, j).getState() == true){
            neighbor++;
        }
          if(gameGrid->getCell(i, j-1).getState() == true){
            neighbor+= 2;
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
            neighbor += 2;
        }

        // NEW CELL >> tempGrid
        getGrid(i, j, neighbor);
        neighbor = 0;
      }
      // LOWER ROW
      // LAST ROW
      else if((i == (row - 1)) && (0 < j && j <= (column - 2))){
        if(gameGrid->getCell(i, j).getState() == true){
          neighbor++;
        }
        if(gameGrid->getCell(i, j-1).getState() == true){
          neighbor += 2;
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
          neighbor+= 2;
        }
        // NEW CELL >> tempGrid
        getGrid(i, j, neighbor);
        neighbor = 0;
        }
      // THESE ARE THE MIDDLE CELLS
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
      }
        // NEW CELL >> tempGrid
        getGrid(i, j, neighbor);
        neighbor = 0;
        }
      }
      // cout << "GAME GRID\n" << gameGrid->toString() << endl;
    }
string MirrorMode::toString(){
  return gameGrid->toString();
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
