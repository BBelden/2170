//Name:       Ben Belden
//Class ID#:  c1004202
//Section:    CSCI 2170-001
//Assignment: Open Lab Assignment #1
//Due:        00:00, February 4, 2013
//Purpose:    To convert words into Pig Latin using given rules. 
//Input:      From data file.
//Output:     Print to terminal

#include <iostream>		//for cout
#include <string>		//for string type
#include <cctype>		//for toupper() and tolower()
#include <fstream>		//for input file stream
#include <iomanip>		//for setw()

using namespace std;

//function prototypes
string process (string& word);
string postProcess (string& pig, bool& punctuate, bool& upper, char punct);

//declare global variables
string word;		//holds the original string to modify to pig-latin
string pig;			//holds the string modified to pig-latin
char punct;		//holds the punctuation from the original word to add to the modified word
bool punctuate = false;		//used to flag a word with punctuation
bool upper = false;			//used to flag a word with a capital first letter

//main function
int main ()
{
	//declare local variables
	ifstream myFile;		//input file stream from pre-determined input file
	string word1;			//holds the first word in a hyphenation
	string word2;			//holds the second word in a hyphenation
	string pig1;			//holds the first word in a hyphenation after modification
	string pig2;			//holds the second word in a hyphenation after modification
	int find;				//holds the value used to identify the index of the hyphen
	bool hyphen = false;	//used to flag a word with a hyphen
	
	myFile.open("pig.txt"); 	//open pre-determined file
	
	myFile >> word;				//priming read
	
	//end-of-file loop
	while (myFile)
	{
		cout << setw(8) << word;			//output word as read to terminal
		
		//test for hyphenation
		find = word.find('-');	
		if (word[find] == '-' && find != string::npos)
			hyphen = true;					//set flag to process as a hyphenated word
		
		//process hyphenated word
		if (hyphen)
		{
			word1 = word.substr(0, find);	//grab the first word in the hyphenation
			word2 = word.substr(find+1);	//grab the second word in the hyphenation
			pig1 = process(word1);  		//pass first word to process function
			pig2 = process(word2);			//pass second word to process function
			pig = pig1 + '-' + pig2;		//concatenate processed words with hyphen
		}
		
		//process non-hyphenated word
		if (!hyphen)
				pig = process(word);		//pass word to process function

		
		cout << "     " << pig << endl;		//output modified word to terminal
		
		hyphen = false;			//reset hyphen to false for the next word
		myFile >> word;			//get next word
	}
	
	myFile.close ();			//close file
	
	return 0;
	
}


//function definitions

//************************************************************************************

string process(string& word)
//Purpose: Identify different types of words based on punctuation, capitalization, 
//and vowel placement. Identifies vowel split points based on pre-determined rules.
//Then modifies the original word into pig latin.
//Precondition: original word has any hyphens removed.
//Postcondition: original word has been modified completely into pig latin.
{
	//declare local variables
	char c;					//used to hold a letter in order to change the case
	int split;				//used to identify the index used to split the original word
	string vowel = "aeiouAEIOU";		//used to test for first character vowels
	string yVowel = "aeiouyAEIOUY";		//used to test for split point vowels

	//test for number as first position of string
	if (word[0] + '0' >= 0 && word[0] - '0' <= 9)
		return word;				//pass control to main with word unmodified
	
	//test for capital first letter
	if (word[0] + '0' > 64 && word[0] < 91)
	{
		c = tolower (word[0]);		//set first letter to upper case
		word = c + word.substr(1);	//concatenate new first letter with the rest of the word
		upper = true;				//set flag for postProcess
	}

	//test for words that end with standard punctuation
	if (word[word.length() - 1] == '.' || word[word.length() - 1] == ',' || 
		word[word.length() - 1] == '?' || word[word.length() - 1] == '!')
	{
		punct = word[word.length() - 1];		//holds the punctuation
		//removes the punctuation from the original word
		word = word.substr(0, word.length() - 1);	
		punctuate = true;						//set flag for postProcess
	}
		
	//test for words that begin with "Qu"
	if (word[0] == 'Q' || word[0] == 'q' && word[1] == 'U' || word[1] == 'u')
	{
		split = 2;					//sets split index
		//modifies word to piglatin
		pig = word.substr(split) + word.substr(0, split) + "ay";
		//pass modified word to postProcess function
		pig = postProcess (pig, punctuate, upper, punct);
		return pig;					//pass control to main with completely modified word
	}
		
	//test for first letter vowel
	for (int c = 0; c < vowel.length(); c++)
		if (word[0] == vowel[c])
		{
			split = 1;				//sets split index
			word = 'w' + word;
			//modifies word to piglatin
			pig = word.substr(split) + word.substr(0, split) + "ay";
			//pass modified word to postProcess function
			pig = postProcess (pig, punctuate, upper, punct);
			return pig;				//pass control to main with completely modified word
		}
						
	//finds the split point based on index of first vowel after a consonant
		for (int b = 1; b < word.length(); b++)
			for (int c = 0; c < yVowel.length(); c++)
				if (word[b] == yVowel[c])
				{
					split = b;		//sets split index
					//modifies word to piglatin
					pig = word.substr(split) + word.substr(0, split) + "ay";
					//pass modified word to postProcess function
					pig = postProcess (pig, punctuate, upper, punct);
					return pig;		//pass control to main with completely modified word
				}
				
}

//*************************************************************************************

string postProcess (string& pig, bool& punctuate, bool& upper, char punct)
//Purpose: checks for true flags, returns capital letters and/or punctuation
//to their original locations

//Precondition: original word has been modified, all lower case, no punctuation
//Postcondition: returned any punctuation, returned 1st letter to upper case

{
	//local variable declaration
	char c;				//used to hold a letter in order to change the case 
	
	//add saved punctuation if flagged
	if (punctuate)
	{
		pig = pig + punct;			//concatenate modified word with original punctuation
		punctuate = false;			//reset flag to false
	}
	
	//make new first letter a capital letter if flagged
	if (upper)
	{
		c = toupper (pig[0]);		//set first letter to upper case
		pig = c + pig.substr(1);	//concatenate new first letter with the rest of the word
		upper = false;				//reset flag to false
	}

	return pig;						//return post-processed word and pass control from this function
}


