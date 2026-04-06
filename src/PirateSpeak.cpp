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
int menu() {
    cout << "1. Translate\n"
        "2. Add to Dictionary\n"
        "3. Quit" << endl;
    int choice = 0;
    cin >> choice;
    bool validating = true;
    while (validating) {
        int whips = 0;
        while (cin.fail()) {
            whips++;
            cout << "Arrrr that be no number you scurvy-dog! " << whips << " lashes for your mutiny!\n"
                "*wwwwhp-kish*"<< endl;
            cin.clear();
            cin.ignore();
            cin >> choice;
        }
        if (choice < 1 || 3 < choice) {
            cout << "Matey, if you can't count on your hook, count on your intact limbs." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else { validating = false; }
    }
    return choice;
}

//TODO: Create the addWord() function. It takes no parameters and the return type
//      is void.
//      1) create a Pirate object
//      2) prompt the user to enter a word in english
//      3) prompt the user to enter the pirate translation
//      4) call the object function called addToFile and pass both words as parameters
void addWord() {
    Pirate wordLoot;
    string engWord = "";
    cout << "We hear you have a new word in the Queen's english for yer crewmates?" << endl;
    while (cin.fail()) {
        cout << "Make em walk the plank! They've invented a new kind of mutiny!" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    getline(cin, engWord);
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string parWord = "";
    cout << "Blast it all laddie, what does it mean?" << endl;
    while (cin.fail()) {
        cout << "Make em walk the plank! They've hornswoggled us!" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    getline(cin, parWord);
    cout << "Ay... I see... " << engWord << " is how those foul blaggarts say " << parWord << "!\n"
        "Add this one to the word loot, me hearties!" << endl;
    wordLoot.addToFile(engWord, parWord);
}

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