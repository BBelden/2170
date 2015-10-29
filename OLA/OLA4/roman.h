//*******************************************************************************************************
//*******************************************************************************************************
//Name:       Ben Belden
//Class ID#:  c1004202
//Section:    CSCI 2170-001
//Assignment: Open Lab Assignment #4
//Due:        00:00, March 20, 2013
//Purpose:    Creates a class to that contains the value of a Roman numeral and it's equivalent integer. 
//            Performs functions on Roman numerals: reads a Roman numeral from standard input, sets the 
//            data members of the class, converts Roman numeral to integers, converts integer to Roman 
//            numeral, perform arithmetic on the values by way of overloaded operators.
//Input:      From hard coded data and standard input.
//Output:     Print to terminal.
//File:       roman.h
//
//This is the specification (header) file for the roman class.


#include <string>
using namespace std;

//prevent multiple inclusions
#ifndef ROMAN
#define ROMAN

class Roman
{
public:

	Roman ();					//default constructor
	Roman (string rInput);		//alternate constructor

	void Set(string rInput);	//sets values of private data members from a given string
	
	void PrintRomanString();	//prints romanString
	void PrintRomanValue();		//prints romanValue
	
	//operator overload methods for the roman class
	Roman operator + (const Roman& rhs);
	Roman operator - (const Roman& rhs);
	Roman operator * (const Roman& rhs);
	Roman operator / (const Roman& rhs);

private:
	//methods
	int RomanToArabic(string romanNumeral);		//converts Roman numeral to it's integral equivalent
	string ArabicToRoman(int number);			//converts integer to it's Roman numeral equivalent

	//data members
	string romanString;			//Roman numeral string
	int romanValue;				//integer value of Roman numeral
};

#endif

//*******************************************************************************************************
//*******************************************************************************************************
