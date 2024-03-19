#include <iostream>
#include "WordCombo.h"
#include "WordFinder.h"

// C:/Users/devin/Documents/AA School/Junior Year/CSC Data Structs/Assignment 3/Assignment 3/bigDictionary.txt
using namespace std;

int main()
{

	WordFinder wf("C:/Users/devin/Documents/AA School/Junior Year/CSC Data Structs/Assignment 3/Assignment 3/bigDictionary.txt");

	WordCombo results;

	bool tempBool = wf.makeWordsFromWord("ihaveafriendwhosenameisjane", results); // use a helper function, copy/paste my current makeWords into a helper function, and makeWords will call helper with a newly created vector of words parameter

	string retString = results.toString();
	cout << retString;
}                                 // carton , ihaveafriendwhosenameisjane