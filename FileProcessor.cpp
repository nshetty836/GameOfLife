#include <fstream>
#include "FileProcessor.h"

using namespace std;

//constructor
FileProcessor::FileProcessor(){
  rows = 5;
  columns = 5;
  allCells = "";
}

FileProcessor::FileProcessor(int r, int c){
  rows = r;
  columns = c;
  allCells = "";
}


//reading file and getting height and width
void FileProcessor::readFile(string fileName){
  ifstream fileIn;
  fileIn.open(fileName);
  string tempLine;
  if (fileIn.eof() == false){
    fileIn >> rows;
    fileIn >> columns;
  }

  while(fileIn.eof() == false){
    fileIn >> tempLine;
    allCells += tempLine;
  }

  fileIn.close();

}
