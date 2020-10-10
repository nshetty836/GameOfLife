#include "GameModes.h"
#include <iostream>
#include <unistd.h>


GameModes::GameModes(){}
GameModes::GameModes(int rows, int columns, float popDensity){
  row = rows;
  column = columns;

  gameGrid = new Grid(row, column, popDensity);
  tempGrid = new Grid(row, column);
  prevGrid = new Grid(row, column);
  tempGrid->setGrid(gameGrid);

}

GameModes::GameModes(string fileName){
  gameGrid = new Grid(fileName);
  row = gameGrid->getRows();
  column = gameGrid->getColumns();

  tempGrid = new Grid(row, column);
  prevGrid = new Grid(row, column);
  tempGrid->setGrid(gameGrid);
}
GameModes::~GameModes(){
  delete prevGrid;
  delete gameGrid;
  delete tempGrid;
}

void GameModes::getGrid(int i, int j, int nc){
    if(nc == 3){
      tempGrid->gridArray[i][j].setAlive();
    }
    //one or less neighbors = death
    else if(nc == 0){
      tempGrid->gridArray[i][j].setDead();
    }
    //one or less neighbors = death
    else if(nc == 1){
      tempGrid->gridArray[i][j].setDead();
    }
    //two neighbors = no change / stable
    else if(nc == 2){
      tempGrid->gridArray[i][j] = gameGrid->getCell(i,j);
    }
    // 4+ neighbors = death
    else if(nc == 4){
      tempGrid->gridArray[i][j].setDead();
    }
    else{
      tempGrid->gridArray[i][j].setDead();
    }
}

//copies tempGrid onto gameGrid and clears tempGrid for next gen
void GameModes::fixGrids(){
  prevGrid->setGrid(gameGrid);
  gameGrid->setGrid(tempGrid);

}

void GameModes::advanceGen(){}
void GameModes::playGame(int outChoice){ //automatic pauses or use keys to see each board
  int genCount = 1;
  int repeatCount = 0;
  do{
    cout << "Generation " << genCount << endl;
    advanceGen();
    gameGrid->printGrid();
    if(outChoice == 1){
      sleep(1);    //waits for 1 second before printing next
    }
    else
      cin.get(); //user presses enter before continuing

    if(gameGrid->equals(tempGrid) || tempGrid->isEmpty())
      break;

    if(tempGrid->equals(prevGrid)){
      repeatCount++;
    }
    else if(repeatCount > 0){
      repeatCount = 0;
    }

    fixGrids();

    genCount++;
  }while(repeatCount < 2 && genCount <= 5001);
}

void GameModes::playGame(string fileOutName, int maxGens){
  int genCount = 1;
  int repeatCount = 0;
  do{
    advanceGen();
    gameGrid->printToFile(fileOutName, genCount);
    if(gameGrid->equals(tempGrid) || tempGrid->isEmpty())
      break;

    if(tempGrid->equals(prevGrid)){
      repeatCount++;
    }
    else if(repeatCount > 0){
      repeatCount = 0;
    }

    fixGrids();

    genCount++;
  }while(repeatCount < 2 && genCount <= maxGens);

}
