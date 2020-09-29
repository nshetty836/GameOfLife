#include <iostream> //pre-processor directive
using namespace std;
class FileReader{

public:
  FileReader();//default constructor
  ~FileReader();//destructor
  void readFile(string fileName);
  int height;
  int width;
};
