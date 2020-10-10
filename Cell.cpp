#include "Cell.h"
using namespace std;

//default constructor
Cell::Cell(){
	isAlive = false;
}

//overloaded constructor
Cell::Cell(bool alive ){
	isAlive = alive;
}

//destructor
Cell::~Cell(){}

//return true if cell is alive and false if dead
bool Cell::getState(){
	if(isAlive == true)
		return true;
	else if (isAlive == false)
		return false;
}

//set state to the given boolean value
void Cell::setState(bool alive){
	isAlive = alive;
}

//set the cell to dead
void Cell::setDead(){
	isAlive = false;
}

//set the cell to alive
void Cell::setAlive(){
	isAlive = true;
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
