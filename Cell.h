#include <iostream>
using namespace std;
class Cell{
	public:
		Cell();
		Cell(bool alive);
		~Cell();
		bool getState();
		void setDead();
		void setAlive();
		bool equals(Cell c);
		void updateState(Cell *neighbors[]); //idk if this will work (pointer?)
		string toString(); // "-" for dead cells and "X" for live cells


	private:
		bool isAlive;

};
