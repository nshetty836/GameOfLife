#include <vector>
#include <iostream>
using namespace std;
class Cell{
	public:
		Cell();
		Cell(bool alive);
		~Cell();
		void setDead(bool alive);
		void setAlive();
		void updateState(vector<Cell> neighbors ); //idk if this will work (pointer?)
		string toString(); // "-" for dead cells and "X" for live cells


	private:
		bool isAlive;

};
