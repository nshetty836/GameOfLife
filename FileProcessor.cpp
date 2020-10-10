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

bool FileProcessor::checkFile(string fileName){
  ifstream fileIn;
  fileIn.open(fileName);
  if (fileIn.is_open() == false)
  {
    return false;
  }
  return true;
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

void FileProcessor::writeFile(string outFileName, string output){
    // open file
    ofstream fout;

    // override whatever content is in this
    fout.open(outFileName, ios_base::app);

    fout << output << endl;

    fout.close();
}

void FileProcessor::clearFile(string outFileName){
  ofstream fout;
  fout.open(outFileName);
  fout.close();
}
