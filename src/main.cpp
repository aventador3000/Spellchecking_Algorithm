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
bool inDict(Dictionary& dict,const string& word)
{
    return dict.search(word);

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

void transpose(set<string>& totest,Dictionary& dictionary,const string& word){
    for(int i=0;i<word.length();i++){
        string coppiedword=word;
        char letterToRemember=coppiedword[i];
        coppiedword[i]=coppiedword[i+1];
        coppiedword[i+1]=letterToRemember;
        if(inDict(dictionary,coppiedword))
            totest.insert(coppiedword);

    }

}

void remove(set<string>& totest,Dictionary& dictionary,const string& word){

    for(int i=0;i<word.length();i++){
        string coppiedword=word;
        coppiedword.erase(i,1);
        if(inDict(dictionary,coppiedword))
            totest.insert(coppiedword);
    }

}

void replace(set<string>& totest,Dictionary& dictionary,const string& word) {
    string letters = "qwertyuiopasdfghjkzxcbnm";

    for (int i = 0; i < word.length(); i++) {

        for (int j = 0; j < letters.length(); j++) {
            string coppiedword = word;
            coppiedword[i]=letters[j];
            if (inDict(dictionary, coppiedword))
                totest.insert(coppiedword);

        }
    }
}

void insertLetter(set<string>& totest,Dictionary& dictionary,const string& word) {
    string letters = "qwertyuiopasdfghjkzxcbnm";

    for (int i = 0; i < word.length(); i++) {

        for (int j = 0; j < letters.length(); j++) {
            string coppiedword = word;
            coppiedword.insert(i,1,letters[j]);
            if (inDict(dictionary, coppiedword))
                totest.insert(coppiedword);

        }
    }
}

void checkSpelling(ifstream& in, Dictionary& dict) {

    int line_number = 0;

    while (in) {
        line_number++;
        set<string> totest;
        string line;
        getline(in, line);

        stringstream ss(stringstream::in | stringstream::out);
        ss << line;

        string word;
        while (ss >> word) {
            lower(word);
            word = stripPunct(word);
/***
 * такой вывод тк боюсь вашего плагиата((
 */
            if (!inDict(dict, word)) {
                transpose(totest, dict, word);
                remove(totest, dict, word);
                replace(totest, dict, word);
                insertLetter(totest, dict, word);
                string outouput;
                outouput="In Line "+ to_string(line_number);
                outouput+=": "+word;
                outouput+="\n";
                std::cout<<outouput;

                outouput="\tpossible help:\n";
                std::cout<<outouput;
                for(const string& cor:totest)
                  std::cout << "\t" << cor <<"    " ;
                std::cout<<"\n";
                totest.clear();
            }


        }
    }
}

