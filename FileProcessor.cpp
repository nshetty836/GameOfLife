#include <fstream>
#include "FileProcessor.h"

using namespace std;

//constructor
FileProcessor::FileProcessor(){}

//overloaded constructor-
FileProcessor::FileProcessor(int r, int c){
  rows = r;
  columns = c;
  allCells = "";
}

//checks if file can be opened
bool FileProcessor::checkFile(string fileName){
  ifstream fileIn;
  fileIn.open(fileName);
  if (fileIn.is_open() == false)
  {
    return false;
  }
  return true;
}


//reading file and getting rows, columns, and string of grid
void FileProcessor::readFile(string fileName){
  ifstream fileIn;
  fileIn.open(fileName);
  string tempLine;

  //getting rows and columns
  if (fileIn.eof() == false){
    fileIn >> rows;
    fileIn >> columns;
  }

  //adding rest of file to string
  while(fileIn.eof() == false){
    fileIn >> tempLine;
    allCells += tempLine;
  }
  fileIn.close();
}

//writing given string to file
void FileProcessor::writeFile(string outFileName, string output){
    ofstream fout;
    // override whatever content is in the file
    fout.open(outFileName, ios_base::app);
    fout << output << endl;
    fout.close();
}

//clear file
void FileProcessor::clearFile(string outFileName){
  ofstream fout;
  fout.open(outFileName);
  fout.close();
}
