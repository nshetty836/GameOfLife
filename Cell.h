#include <iostream>
using namespace std;
class Cell{
	public:
		Cell();
		Cell(bool alive);
		~Cell();
		void setState(bool alive);
		bool getState();
		void setDead();
		void setAlive();
		bool equals(Cell c);
		string toString();

	private:
		bool isAlive;

};
