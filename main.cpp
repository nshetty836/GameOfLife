#include <iostream>
#include <fstream>

#include "FileReader.h"
#include "Grid.h"

using namespace std;
int main(int argc, char** argv){
  FileReader *fr = new FileReader();
  string fileName;

  //TODO: ask user if they want a random game or input a file
  // cout << "Enter file name: ";
  // cin >> fileName;
  // fr->readFile(fileName);
  Grid *myGrid = new Grid(7,7);

  cout << myGrid -> toString() << endl;
}
