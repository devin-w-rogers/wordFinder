#pragma once

#include <iostream>
#include "WordCombo.h"

using namespace std;

class WordFinder
{
public:
    WordFinder(string dictionaryPath);
    bool makeWordsFromWord(string word, WordCombo &newWord);
    bool search(string searchWord);
    bool checkForWords(string searchWord);
    string cleanse(string word);
    bool makeWordsHelper(string word, WordCombo &newWord, vector <string> &allWords);
private:
    vector <string> dictionary;
};

