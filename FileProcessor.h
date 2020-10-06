#include <iostream> //pre-processor directive
using namespace std;
class FileProcessor{

public:
  FileProcessor();//default constructor
  FileProcessor(int r, int c);
  ~FileProcessor();//destructor
  void readFile(string fileName);
  int rows;
  int columns;

  string allCells;

};
