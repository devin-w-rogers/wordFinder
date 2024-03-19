#include "WordFinder.h"
#include <fstream>

using namespace std;

WordFinder::WordFinder(string dictionaryPath)
{
	fstream infile;
    infile.open(dictionaryPath);
    if (infile.good())
    {
        string word;
        infile >> word;

        while (infile.good()) {
            dictionary.push_back(word);
            infile >> word;
        }
    }
    else
    {
        cout << "Error opening the file at: " << dictionaryPath << endl;
    }
}

bool WordFinder::makeWordsFromWord(string word, WordCombo &newWord)
{
    newWord.setOriginalWord(word);
    bool retVal = false;
    vector <string> allWords;

    retVal = makeWordsHelper(word, newWord, allWords);

    //cout << "Contents of allWords: " << endl;
    //for (int i = 0; i < allWords.size(); i++) {
    //    cout << allWords[i] << endl;
    //}

    return retVal;
}

bool WordFinder::makeWordsHelper(string word, WordCombo &newWord, vector <string> &allWords)
{
    bool retVal = false;
    word = cleanse(word);

    for (int i = 1; i < word.size() + 1; i++) {
        string firstSub = word.substr(0, i);
        string lastSub = word.substr(i);
        if (search(firstSub) == true) {
            allWords.push_back(firstSub);
            if (lastSub.length() == 0) {
                newWord.addWords(allWords);
                //all words were so far in dictionary, add the allWords vector to the WordCombo
                retVal = true;
            }
            else {
                retVal = makeWordsHelper(lastSub, newWord, allWords);
            }
            //cout << firstSub << " " << lastSub << endl;
            allWords.pop_back();
        }
    }

    return retVal;
}

bool WordFinder::search(string searchWord)
{
    bool retVal = false;

    int start = 0;
    int end = dictionary.size() - 1;
    int middle;

    while (start <= end)
    {
        middle = (start + end) / 2;

        if (searchWord == dictionary[middle])
        {
            retVal = true;
            break;
        }
        else if (searchWord < dictionary[middle])
        {
            end = middle - 1;
        }
        else
        {
            start = middle + 1;
        }
    }

    return retVal;
}

bool WordFinder::checkForWords(string searchWord) //maybe use this to find if "to" is valid while leaving "n" remaining, which is not a word
{ 
    bool retVal = false;
    for (int j = 0; j < dictionary.size(); j++) { //loop through and find all valid words in this last half subString
        if (searchWord == dictionary[j]) {
            retVal = true;
            cout << searchWord << endl;
            break;
        }
    }
    return retVal;
}

string WordFinder::cleanse(string word)
{
    for (int i = 0, length = word.size(); i < length; i++)
    {
        word[i] = tolower(word[i]);
        if (ispunct(word[i]) || isspace(word[i]))
        {
            word.erase(i--, 1);
            length = word.size();
        }
    }
    return word;
}