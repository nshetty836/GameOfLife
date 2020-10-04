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
 // not sure what to put in here yet
  	}
}

//destructor
classicMode::~classicMode(){
delete gameGrid1;
delete gameGrid2;

}

void classicMode::runSimulation(){


  for(int i = 0; i < row; i++){
    for(int j = 0; j < column; j++){
      neighbor = 0;

      //corner cells
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

       

      //corner cells
      }else if((i == (row - 1)) && (j == 0)){
        if(gameGrid1[i][j+1].toString() == “X”){
          neighbor++;
        }
        if(gameGrid1[i-1][j].toString() == “X”){
          neighbor++;
        }
        if(gameGrid1[i-1][j+1].toString() == “X”){
          neighbor++;
        }

      
      //upper column
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

     

      //lower column
      }
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

 
      }
      //upper row
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

      }
      
      //lower row
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
      }
      //cells in the middle
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
      }
    }
  }
}

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
