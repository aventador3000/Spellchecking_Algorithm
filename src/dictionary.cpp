#include <iostream>
#include <fstream>
#include <string>
#include "dictionary.h"


Dictionary::Dictionary(string filename) {
        string addedwords="";
        ifstream incomefile(filename);
        if (!incomefile) {
            throw std::invalid_argument("Invalid argument");

        }
        while (!incomefile.eof()) {
            incomefile >> addedwords;
            insert(addedwords);
        }


}
