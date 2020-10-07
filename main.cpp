#include <iostream>
#include <fstream>

// #include "Grid.h"
//#include "ClassicMode.h"
#include "MirrorMode.h"

using namespace std;
int main(int argc, char** argv){
  //FileReader *fr = new FileReader();
  string fileName;

  //TODO: ask user if they want a random game or input a file
  // cout << "Enter file name: ";
  // cin >> fileName;
  // fr->readFile(fileName);
  // fr->readFile(fileName);
  // fr->readFile(fileName);
  // Grid *g1 = new Grid("cellinput.txt");
  //ClassicMode *cm = new ClassicMode("cellinput.txt");
  MirrorMode *mm = new MirrorMode("cellinput.txt");
  // Grid *g2 = new Grid(7,7);

  // g1 -> randPopulate(.25);
  // g2 -> randPopulate(.5);
  // cout << boolalpha << g1 -> equals(g2) << endl;

/*
  cm -> advanceGen();
  cout << cm -> toString() << endl;
  cm -> advanceGen();
  cout << cm -> toString() << endl;

  cm -> advanceGen();
  cout << cm -> toString() << endl;
*/
  mm -> advanceGen();
  cout << mm -> toString() << endl;

  mm -> advanceGen();
  cout << mm -> toString() << endl;

  mm -> advanceGen();
  cout << mm -> toString() << endl;


  // cout << g2 -> toString() << endl;


  // delete g1;
  // delete g2;
}
