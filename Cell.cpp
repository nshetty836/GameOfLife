#include "Cell.h"
using namespace std;

Cell::Cell(){
	isAlive = false;
}
Cell::Cell(bool alive){
	isAlive = alive;
}

Cell::~Cell(){
}

bool Cell::getState(){
	if(isAlive == true)
		return true;
	else if (isAlive == false)
		return false;
}

void Cell::setState(bool alive){
	isAlive = alive;
}

void Cell::setDead(){
	isAlive = false;
}

void Cell::setAlive(){
	isAlive = true;
}

bool Cell::equals(Cell c){
	bool ret;
	if(c.getState() == isAlive)
		ret = true;
	else
		ret = false;
	return ret;
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
