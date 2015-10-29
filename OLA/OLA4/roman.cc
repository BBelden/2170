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
//File:       roman.cc
//
//This is the implementation file for the roman class


#include "roman.h"		//class header file
#include <iostream>		//for cin/cout
#include <string>		//for string data type
#include <cstdlib>		//for abs() function

using namespace std;

//default constructor.
Roman::Roman(){romanString = "I"; romanValue = 1;}

//*******************************************************************************************************

//alternate constructor
Roman::Roman (string rInput){Set(rInput);}

//*******************************************************************************************************

//This method sets the value of romanString from a given string and calls
//a private method to set the value of romanValue
void Roman::Set(string rInput)
{
	romanString = rInput;
	romanValue = RomanToArabic(romanString);
}

//*******************************************************************************************************

//This method prints the value of romanString as part of a larger statement via standard output
void Roman::PrintRomanString()
{
	cout << "The roman numeral is: " << romanString << endl;
}

//*******************************************************************************************************

//This method prints the value of romanValue as part of a larger statement via standard output
void Roman::PrintRomanValue()
{
	cout << "The arabic numeral is: " << romanValue << endl;
}

//*******************************************************************************************************

//This method overloads the + operator for the roman class
Roman Roman::operator + (const Roman& rhs)
{
	Roman result;
	result.romanValue = romanValue + rhs.romanValue;
	result.romanString = ArabicToRoman(result.romanValue);
	return result;
}

//*******************************************************************************************************

//This method overloads the - operator for the roman class and removes any instances
//of negative integers with the abs() function
Roman Roman::operator - (const Roman& rhs)
{
	Roman result;
	result.romanValue = romanValue - rhs.romanValue;
	result.romanValue = abs(result.romanValue);				
	result.romanString = ArabicToRoman(result.romanValue);
	return result;
}

//*******************************************************************************************************

//This method overloads the * operator for the roman class
Roman Roman::operator * (const Roman& rhs)
{
	Roman result;
	result.romanValue = romanValue * rhs.romanValue;
	result.romanString = ArabicToRoman(result.romanValue);
	return result;
}

//*******************************************************************************************************

//This method overloads the / operator for the roman class and removes any instances
//of negative integers with the abs() function
Roman Roman::operator / (const Roman& rhs)
{
	Roman result;
	result.romanValue = romanValue / rhs.romanValue;
	result.romanValue = abs(result.romanValue);				
	result.romanString = ArabicToRoman(result.romanValue);
	return result;
}

//*******************************************************************************************************

//Private method implementation

//This method converts a string containing Roman numeral characters into it's integral equivalent by 
//populating a temporary integer array with the converted values of the character array (string), then 
//summing appropriately. Assumes the passed string contains no more than 10 characters.
int Roman::RomanToArabic(string romanNumeral)
{
	int temp[10];			//declares an integer array and assumes there will be up to 10 indexes used
	
	//Populates the array with integer values equal to the values of the Roman numerals at the same index
	for (int i = 0; i < romanNumeral.length(); i++)
	{
		if (romanNumeral[i] == 'M')
			temp[i] = 1000;
		else if (romanNumeral[i] == 'D')
			temp[i] = 500;
		else if (romanNumeral[i] == 'C')
			temp[i] = 100;
		else if (romanNumeral[i] == 'L')
			temp[i] = 50;
		else if (romanNumeral[i] == 'X')
			temp[i] = 10;
		else if (romanNumeral[i] == 'V')
			temp[i] = 5;
		else if (romanNumeral[i] == 'I')
			temp[i] = 1;
	}

	int sum = 0; 							//holds the value of the sum of each integer in the array
	int i = romanNumeral.length() - 1;		//sets the counter to the last index of the array
	//sums the values of each index in the array
	while (i >= 0)
	{
		sum = sum + temp[i];
		if (!(i+1 >= romanNumeral.length()))
			//tests for higher value to the right of the index and subtracts it from the sum
			if (temp[i] < temp[i+1])
				sum = sum - (2 * temp[i]);
		i--;
	}
	
	return sum;								//passes control back to calling function
	
}

//*******************************************************************************************************

//This method converts an integer to it's Roman numeral equivalent. Assumes string contains only capital 
//letters and only valid Roman numeral letters. Assumes no value higher than 9999.
string Roman::ArabicToRoman(int number)
{
	int one = (number / 1) % 10;		//used to hold the value of the ones column of an integer
	int ten = (number / 10) % 10;		//used to hold the value of the tens column of an integer
	int hund = (number / 100) % 10;		//used to hold the value of the hundreds column of an integer
	int thou = (number / 1000) % 10;	//used to hold the value of the thousands column of an integer
	//holds the value of the converted Roman numeral from each integral column to be concatenated
	string temp;						
	string hold;						//used to hold the Roman numera string without spaces
	string roman;						//used to hold the concatenated Roman numeral
		
	//converts ones column into roman numeral and concatenates it to "temp"
	switch (one)
	{
		case 1 : temp = "I"; break;
		case 2 : temp = "II"; break;
		case 3 : temp = "III"; break;
		case 4 : temp = "IV"; break;
		case 5 : temp = "V"; break;
		case 6 : temp = "VI"; break;
		case 7 : temp = "VII"; break;
		case 8 : temp = "VIII"; break;
		case 9 : temp = "IX"; break;
		default : temp = " "; break;
	}
	roman = temp + roman;
	
	//converts tens column into roman numeral and concatenates it to "temp"
	switch (ten)
	{
		case 1 : temp = "X"; break;
		case 2 : temp = "XX"; break;
		case 3 : temp = "XXX"; break;
		case 4 : temp = "XL"; break;
		case 5 : temp = "L"; break;
		case 6 : temp = "LX"; break;
		case 7 : temp = "LXX"; break;
		case 8 : temp = "LXXX"; break;
		case 9 : temp = "XC"; break;
		default : temp = " "; break;
	}
	roman = temp + roman;
	
	//converts hundreds column into roman numeral and concatenates it to "temp"
	switch (hund)
	{
		case 1 : temp = "C"; break;
		case 2 : temp = "CC"; break;
		case 3 : temp = "CCC"; break;
		case 4 : temp = "CD"; break;
		case 5 : temp = "D"; break;
		case 6 : temp = "DC"; break;
		case 7 : temp = "DCC"; break;
		case 8 : temp = "DCCC"; break;
		case 9 : temp = "CM"; break;
		default : temp = " "; break;
	}
	roman = temp + roman;

	//converts thousands column into roman numeral and concatenates it to "temp"
	switch (thou)
	{
		case 1 : temp = "M"; break;
		case 2 : temp = "MM"; break;
		case 3 : temp = "MMM"; break;
		case 4 : temp = "MMMM"; break;
		case 5 : temp = "MMMMM"; break;
		case 6 : temp = "MMMMMM"; break;
		case 7 : temp = "MMMMMMM"; break;
		case 8 : temp = "MMMMMMMM"; break;
		case 9 : temp = "MMMMMMMMM"; break;
		default : temp = " "; break;
	}
	roman = temp + roman;
	
	//removes any spaces after concatenation of "temp"
	for (int i = 0; i < roman.length(); i++)
	{
		if (roman[i] != ' ')
			hold = hold + roman[i];
	}
	roman = hold;			
	
	return hold;			//passes control back to calling function
}

//*******************************************************************************************************
//*******************************************************************************************************
