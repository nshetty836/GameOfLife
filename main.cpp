#include <iostream>
#include <fstream>

#include "FileReader.h"

using namespace std;
int main(int argc, char** argv){
  FileReader *fr = new FileReader();
  string fileName;

  //TODO: ask user if they want a random game or input a file
  cout << "Enter file name: ";
  cin >> fileName;
  fr->readFile(fileName);
}
