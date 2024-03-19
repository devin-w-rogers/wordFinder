#pragma once

#include <string>
#include <vector>

using namespace std;

class WordCombo
{
public:
    void setOriginalWord(string word);
    void addWords(const vector < string >& newCombo);
    void clear();
    string toString();
private:
    string originalWord;
    vector < vector < string > > words;
};

