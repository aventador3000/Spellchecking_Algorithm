#ifndef  _DICTIONARY_H_ 
#define  _DICTIONARY_H_

#include  <iostream>
#include  <vector>
#include  <list>
#include  <algorithm>
#include  <string>
#include  <stdlib.h>

#include  "hashset.h"
#include  "hashset.cpp"

using namespace std;

class hash_function
{
public:

    unsigned int operator()( const string& s )  const {
        unsigned int key= 37;
        unsigned long hash=0;
        unsigned long mem=1;

        for(int i=0;i<s.size();++i)
        {
            hash+=(s[i]+ 'a'+1)*mem;
            mem*=key;

        }
        return (hash&0xFFFFF);

    }
};

class equality
{
public:
    equality() {}
    bool  operator()( const string& A, const string& B )  const 
    {
        return  (A == B);
    }
};

class Dictionary: public HashSet<string, hash_function, equality> {

public:
	Dictionary(string filename);


};
#endif // _DICTIONARY_H_
