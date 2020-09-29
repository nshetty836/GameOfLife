#include <fstream>
#include "FileReader.h"

using namespace std;

//constructor
FileReader::FileReader(){
  height = 0;
  width = 0;
}

//reading file and getting height and width
void FileReader::readFile(string fileName){
  ifstream fileIn;
  fileIn.open(fileName);
  if (fileIn.eof() == false)
  {
    fileIn >> height;
    fileIn >> width;
    //TODO: Read grid from file and make Grid Object with those specs
  }

  cout << "Height: " << height << endl;
  cout << "Width: " << width << endl;
}
