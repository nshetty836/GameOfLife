#include "GameModes.h"
#include <iostream>
#include <unistd.h>

//default constructor
GameModes::GameModes(){}

//overloaded constructor- make random grid with certain population density
GameModes::GameModes(int rows, int columns, float popDensity){
  row = rows;
  column = columns;

  gameGrid = new Grid(row, column, popDensity);
  nextGrid = new Grid(row, column);
  prevGrid = new Grid(row, column);
  nextGrid->setGrid(gameGrid);

}

//overloaded constructor- make grid from a given file
GameModes::GameModes(string fileName){
  gameGrid = new Grid(fileName);
  row = gameGrid->getRows();
  column = gameGrid->getColumns();

  nextGrid = new Grid(row, column);
  prevGrid = new Grid(row, column);
  nextGrid->setGrid(gameGrid);
}

//destructor
GameModes::~GameModes(){
  delete prevGrid;
  delete gameGrid;
  delete nextGrid;
}

//updating next generation into nextGrid
void GameModes::getGrid(int i, int j, int nc){
    //3 neighbors = alive
    if(nc == 3){
      nextGrid->gridArray[i][j].setAlive();
    }
    //one or less neighbors = death
    else if(nc == 0){
      nextGrid->gridArray[i][j].setDead();
    }
    //one or less neighbors = death
    else if(nc == 1){
      nextGrid->gridArray[i][j].setDead();
    }
    //two neighbors = no change / stable
    else if(nc == 2){
      nextGrid->gridArray[i][j] = gameGrid->getCell(i,j);
    }
    // 4 neighbors = death
    else if(nc == 4){
      nextGrid->gridArray[i][j].setDead();
    }
    // 4+ neighbors = death
    else{
      nextGrid->gridArray[i][j].setDead();
    }
}

// copies gameGrid onto prevGrid and nextGrid onto gameGrid
void GameModes::fixGrids(){
  prevGrid->setGrid(gameGrid);
  gameGrid->setGrid(nextGrid);

}

// advanceGen overloaded in each mode
void GameModes::advanceGen(){}

/* advance generation until the grid stabilizes and outputs with
automatic pauses or pressing enter to see each generation */
void GameModes::playGame(int outChoice){
  int genCount = 1;
  int repeatCount = 0;
  cin.get();
  do{
    cout << "Generation " << genCount << endl;
    advanceGen();
    gameGrid->printGrid();
    if(outChoice == 1){
      sleep(1);    //waits for 1 second before printing next
    }
    else
       cin.get();  //user presses enter before continuing

    //if gameGrid stabilizes or if the grid is empty, end
    if(gameGrid->equals(nextGrid) || nextGrid->isEmpty())
      break;

    //checking for an alternating repeating pattern
    if(nextGrid->equals(prevGrid)){
      repeatCount++;
    }
    else if(repeatCount > 0){
      repeatCount = 0;
    }
    fixGrids();
    genCount++;
  }
  while(repeatCount < 2 && genCount <= 5001);
}

/* advance generation until the grid stabilizes or maxGens is reached
  and outputs to a given file */
void GameModes::playGame(string fileOutName, int maxGens){
  int genCount = 1;
  int repeatCount = 0;
  do{
    advanceGen();
    gameGrid->printToFile(fileOutName, genCount);

    //if gameGrid stabilizes or if the grid is empty, end
    if(gameGrid->equals(nextGrid) || nextGrid->isEmpty())
      break;

    //checking for an alternating repeating pattern
    if(nextGrid->equals(prevGrid)){
      repeatCount++;
    }
    else if(repeatCount > 0){
      repeatCount = 0;
    }

    fixGrids();

    genCount++;
  }while(repeatCount < 2 && genCount <= maxGens);

}
