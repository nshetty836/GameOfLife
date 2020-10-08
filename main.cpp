#include <iostream>
#include <fstream>
#include "ClassicMode.h"
// #include "DoughnutMode.h"
#include "MirrorMode.h"

using namespace std;
int main(int argc, char** argv){

    MirrorMode *mm = new MirrorMode("cellinput.txt");
    ClassicMode *cm = new ClassicMode("cellinput.txt");


    cout << "Gen 1" << endl;
    cout << mm -> toString() << endl;

    mm -> advanceGen();

    cout << "Gen 2" << endl;
    cout << mm -> toString() << endl;
    mm -> advanceGen();
    cout << "Gen 3" << endl;

    cout << mm -> toString() << endl;

    cout << "Gen 4" << endl;

    mm -> advanceGen();
    cout << mm -> toString() << endl;

    cout << "Gen 1" << endl;
    cout << cm -> toString() << endl;

    cm -> advanceGen();

    cout << "Gen 2" << endl;
    cout << cm -> toString() << endl;
    cm -> advanceGen();
    cout << "Gen 3" << endl;

    cout << cm -> toString() << endl;

    cout << "Gen 4" << endl;

    cm -> advanceGen();
    cout << cm -> toString() << endl;

}
