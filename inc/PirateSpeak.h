#ifndef PIRATESPEAK_H
#define PIRATESPEAK_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <filesystem>

using namespace std;
namespace fs = filesystem;

class Pirate {
    private:
        fs::path treasureMap = fs::current_path();
    public:
        Pirate() {
            while (treasureMap.has_parent_path()) {
                if (fs::exists(treasureMap / "files")) {
                    treasureMap = (treasureMap / "files").string() + "\\pirate.csv";
                    break;
                }
                else treasureMap = treasureMap.parent_path();
            }
        }

        string translateWord(string word){
            //TODO: Enter the path to the text file in the double quotes
            ifstream fin(treasureMap, ios::in);
            fin.open("pirate.csv");
            string english, pirate;
            
            if (!fin.is_open()) cout << "The treasure map has torn!" << endl;
            string entry;
            //TODO: The way that an ifstream works is that it reads everything in the 
            //      csv file. 
            //      1) Create a while loop that does not terminate until the file
            //         has been read fully
            //      2) using getline(), read the english word
            //      3) using getline(), read the pirate word
            //      4) if the english word equals the word that is being passed,
            //         then close the file and return the pirate word
            //      5) otherwise, close the file and just return the word being passed
            while (fin >> entry) {
                cout << entry << endl;
            }
            fin.close();
            return word;
        }

        void addToFile(string english, string pirate){
            //TODO: append the passed words to the csv file and close the file
            //      remember to delimit the words with a comma
        }
};
#endif
