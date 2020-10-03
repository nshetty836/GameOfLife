#include "Cell.h"
#include <vector>
using namespace std;

Cell::Cell(){
	isAlive = false;
}
Cell::Cell(bool alive ){
	isAlive = alive;
}

Cell::~Cell(){
}

void Cell::setDead(bool alive){
	isAlive = false;
}
void Cell::setAlive(){ //took out parameter bool alive
	isAlive = true;
}

//TODO: FINISH THIS 
void Cell::updateState(vector<Cell> neighbors ){ //idk if this will work  (pointer?)

}

 // "-" for dead cells and "X" for live cells
string Cell::toString(){
	string ret;
	if (isAlive == true)
		ret = "X";
	else
		ret = "-";
	return ret;
}
