#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <set>
#include <iomanip> // setw


#include "dictionary.h"

using namespace std;

void lower(string& s);
string stripPunct(const string& s);
void checkSpelling(ifstream& in, Dictionary& dict);



// program arguments to run, example: main.exe ../../res/wordlist.txt ../../res/test.txt
int main(int argc, char* argv[]) {
	
	// Output usage message if improper command line args were given.
	if (argc != 3)
    {
		cerr << "Usage: " << argv[0] << " wordlist_filename input_file\n";
		return EXIT_FAILURE;
	}

	ifstream inf(argv[2]);
	if (! inf) 
    {
		cerr << "Could not open " << argv[2] << "\n";
		return EXIT_FAILURE;
	}
	
	// Read dictionary, but let user know what we are working on.
	cout << "Loading dictionary, this may take awhile...\n";

	Dictionary d(argv[1]);
    
	checkSpelling(inf, d);

	inf.close();

	return EXIT_SUCCESS;
}

void checkSpelling(ifstream& in, Dictionary& dict) {

	int line_number = 0;

	while (in) 
    {
		line_number++;
		set<string> totest;
		string line;
		getline(in, line);

  	    stringstream ss (stringstream::in | stringstream::out);
		ss << line;
		
		string word;
		while (ss >> word) 
        {
            // TODO: Complete the spell check of each word
		}
	}
}

void lower(string& s) {

    // Ensures that a word is lowercase
	for (int i = 0; i < s.length(); i++)
    {
		s[i] = tolower(s[i]);
	}
}

string stripPunct(const string& s) {

	// Remove any single trailing
	// punctuation character from a word.  
	if (ispunct(s[s.length() - 1]) ) 
    {
		return s.substr (0, s.length() - 1);
	}
	else 
    {
		return s;
	}
}
