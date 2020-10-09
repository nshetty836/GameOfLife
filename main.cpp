#include <iostream>
#include <fstream>
#include <ctype.h>
#include "ClassicMode.h"
#include "MirrorMode.h"
#include "DonutMode.h"
#include "FileProcessor.h"

using namespace std;
int main(int argc, char** argv){
    double popDensity;
    bool loop = true;
    bool simulationLoop = true;
    string fileInName, fileOutName;
    char pause;
    int configuration, mode, outChoice, maxGen;
    int rows, columns;
    FileProcessor *fp = new FileProcessor();
    GameModes *game;

    cout << "Welcome to the game of life!" << endl;
    while(loop){
        cout << "Choose configuration type \n1) Random configuration \n2) flat-file configuration \nChoice: " << endl;
        cout << "Enter 1 or 2: ";
        cin >> configuration;

        // RANDOM CONFIGURATION
        if(configuration == 1){
          cout << "Please enter the dimensions for the world." << endl;

          cout << "Enter the number of rows: ";
          cin >> rows;
          cout << "Enter the number of columns: ";
          cin >> columns;

          while(true){
            cout << "Enter a decimal for the population density between: 0 - 1: ";
            cin >> popDensity;
            if(0 < popDensity && popDensity < 1 ){
              break;
            }
            else
              cout << "INVALID, please try again. ";
          }
        }

        // flat-file configuration
        else if(configuration == 2){
          while(true){
            cout << "Enter the name of the file: ";
            cin >> fileInName;
            bool isOpen = fp -> checkFile(fileInName);
            if(isOpen == false){
              cout << "Error! Please enter a valid fileName (ending in .txt)." << endl;
            }
            else
              break;
          }
        }

        else{
          cout << "Error! Please enter 1 or 2. " << endl;
          continue;
        }

        cout << "Modes: \n1) Classic Mode \n2) Mirror Mode \n3) Donut Mode" << endl;
        cout << "Enter the number of the mode you would like to play (1, 2, or 3): ";
        cin >> mode;

      if(configuration == 1){
        switch(mode){
          case 1: game = new ClassicMode(rows, columns, popDensity);
            break;
          case 2: game = new MirrorMode(rows, columns, popDensity);
            break;
          case 3: game = new DonutMode(rows, columns, popDensity);
            break;
        }
      }
      else{
        switch(mode){
          case 1: game = new ClassicMode(fileInName);
            break;
          case 2: game = new MirrorMode(fileInName);
            break;
          case 3: game = new DonutMode(fileInName);
            break;
        }
      }


        //picking output option
        do{
           cout << "\nEnter an option: \n\t1)Brief pauses \n\t2)Press enter key \n\t3)Output to file \nChoice: ";
           cin >> outChoice;
         } while(outChoice != 1 && outChoice != 2 && outChoice != 3);


        //if user wants to map to a file
        if(outChoice == 3){
          //getting output file name from user
          while(true){
            cout << "Please enter the file name: ";
            cin >> fileOutName;
            if(fileOutName.substr(fileOutName.size()-4,4) != ".txt"){
             cout << "Error! Please enter a valid file name (ending in .txt)" << endl;
            }
           else
             break;
         }
         cout << "Enter the max number of generations: " << endl;
         cin >> maxGen;
         game->playGame(fileOutName, maxGen);

       }
       //if user wants the output in the console
       else {
         game->playGame(outChoice);
       }
     }

     delete game;

}
