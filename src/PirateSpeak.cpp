#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "PirateSpeak.h"
using namespace std;

enum Choices {TRANSLATE = 1, ADD, QUIT};
//TODO: Create a function called menu() it will take no parameters
//      and the return type is int.
//      In the function prompt the user to choose 1 of three menus. Translate, Add to
//      Dictionary, or Quit.

//TODO: Create the addWord() function. It takes no parameters and the return type
//      is void.
//      1) create a Pirate object
//      2) prompt the user to enter a word in english
//      3) prompt the user to enter the pirate translation
//      4) call the object function called addToFile and pass both words as parameters

//TODO: Create the translate() function. It takes no parameters and the return type is void
//      1) create a Pirate object
//      2) prompt the user to enter a word
//      3) call the object function called translateWord and pass the word as a parameter

int main() {
  int choice;
  do{
    choice = menu();
    switch(choice){
      case TRANSLATE:
        translate();
        break;
      case ADD:
        addWord();
        break;   
    }
  }while(choice != QUIT);

  return 0;
}