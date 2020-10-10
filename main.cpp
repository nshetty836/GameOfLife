#include <iostream>
#include <fstream>
#include <ctype.h>
#include "ClassicMode.h"
#include "MirrorMode.h"
#include "DonutMode.h"
#include "FileProcessor.h"

using namespace std;
int main(int argc, char** argv){
    float popDensity;
    bool playAgain = true;
    string fileInName, fileOutName;
    int rows, columns, configuration, mode, outChoice, maxGen, playChoice;
    FileProcessor *fp = new FileProcessor();
    GameModes *game;

    cout << "\nWelcome to the game of life!" << endl;
    // loop for whether the user would like to play more than once
    while(playAgain){
        cout << "\nChoose configuration type \n\t1) Random configuration \n\t2) Flat-file configuration \nChoice: ";
        cin >> configuration;

        // RANDOM CONFIGURATION - gets user input for rows, columns, and population density
        if(configuration == 1){
          cout << "\nPlease enter the dimensions for the world." << endl;

          cout << "Enter the number of rows: ";
          cin >> rows;
          cout << "Enter the number of columns: ";
          cin >> columns;

          //loop to check whether user-given population density is between 0 and 1
          while(true){
            cout << "Enter a decimal for the population density between: 0 - 1: ";
            cin >> popDensity;
            if(0 < popDensity && popDensity < 1 ){
              break;
            }
            else
              cout << "Error! Please try again. ";
          }
        }

        // FLAT-FILE CONFIGURATION - gets user input for file name
        else if(configuration == 2){
          //checking whether user-given file name is valid
          while(true){
            cout << "\nEnter the name of the file: ";
            cin >> fileInName;
            bool isOpen = fp -> checkFile(fileInName);
            if(isOpen == false){
              cout << "Error! Please enter a valid file name (ending in .txt)." << endl;
            }
            else
              break;
          }
        }

        //if user enters a number other than 1 or 2, ask again
        else{
          cout << "Error! Please enter 1 or 2. " << endl;
          continue;
        }

      cout << "Modes: \n\t1) Classic Mode \n\t2) Mirror Mode \n\t3) Donut Mode \nChoice: ";
      cin >> mode;

      //creating an instance of the specified mode with random configuration
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
      //creating an instance of the specified mode with flat-file configuration
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

      //picking output option- brief pause, pressing enter key, or outputting to file
      do{
         cout << "\nEnter an option: \n\t1) Brief pauses \n\t2) Press enter key \n\t3) Output to file \nChoice: ";
         cin >> outChoice;
       } while(outChoice != 1 && outChoice != 2 && outChoice != 3);


      //if user wants to map to a file
      if(outChoice == 3){
        //getting output file name from user and checking it is valid
        while(true){
          cout << "\nEnter the file name: ";
          cin >> fileOutName;
          if(fileOutName.substr(fileOutName.size()-4,4) != ".txt"){
           cout << "Error! Please enter a valid file name (ending in .txt)" << endl;
          }
         else
           break;
       }
       //max number of generations in case the game is infinite
       cout << "\nEnter the max number of generations: ";
       cin >> maxGen;

       //playing game and outputting it to file
       game->playGame(fileOutName, maxGen);
       cout << "Successfully outputted to file " << fileOutName << ".\n" << endl;
     }
     //if user wants the output in the console
     else {
       game->playGame(outChoice);
     }
     //asking the user if they would like to exit or keep playing
     cout << "Would you like to play again? Enter '1' or '2'.\n\t1) Yes \n\t2) No \nChoice: ";
     cin >> playChoice;
     if(playChoice == 2){
      cout << "Thank you for playing!\n" << endl;
      playAgain = false;
     }
   }

     delete game;

}
