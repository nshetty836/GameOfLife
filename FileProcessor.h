#include <iostream> //pre-processor directive
using namespace std;
class FileProcessor{

public:
  FileProcessor();//default constructor
  FileProcessor(int r, int c);
  ~FileProcessor();//destructor
  bool checkFile(string fileName);
  void readFile(string fileName);
  void writeFile(string outFileName, string output);
  void clearFile(string outFileName);
  int rows;
  int columns;

  string allCells;

};
