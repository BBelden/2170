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
//File:       ola4.cc
//
//This is the client file for the roman class

#include "roman.h"		//class header file
#include <iostream>		//for cin/cout
#include <string>		//for string data type

using namespace std;

//main function
int main ()
{
	string rInput;				//Roman numeral
	Roman romanOne;				//uses default constructor
	Roman romanTwo;				//uses default constructor
	Roman romanThree("LXVII");	//uses alternate constructor
	Roman romanFour("MDCL");	//uses alternate constructor
	Roman romanTemp;			//for intermediate results
	
	//verify default constructor
	cout << "romanOne:\n";
	romanOne.PrintRomanString();
	romanOne.PrintRomanValue();
	cout << "\nromanTwo:\n";
	romanTwo.PrintRomanString();
	romanTwo.PrintRomanValue();
	cout << endl;
	
	//verify alternate constructor
	cout << "romanThree:\n";
	romanThree.PrintRomanString();
	romanThree.PrintRomanValue();
	cout << "\nromanFour:\n";
	romanFour.PrintRomanString();
	romanFour.PrintRomanValue();
	cout << endl;
	
	//set roman numbers from standard input
	cout << "Please enter a roman numeral\n";
	cout << "(M = 1000, D = 500, C = 100, L = 50, X = 10, V = 5, I = 1)\n";
	cin >> rInput;
	romanOne.Set(rInput);
	
	//set roman numbers from standard input
	cout << "Please enter a smaller roman numeral\n";
	cout << "(M = 1000, D = 500, C = 100, L = 50, X = 10, V = 5, I = 1)\n";
	cin >> rInput;
	cout << endl;
	romanTwo.Set(rInput);
	
	//verify the set operation
	//set operation stores roman string as integer
	cout << "romanOne:\n";
	romanOne.PrintRomanString();
	romanOne.PrintRomanValue();
	cout << "\nromanTwo:\n";
	romanTwo.PrintRomanString();
	romanTwo.PrintRomanValue();
	cout << endl;
	
	//verify arithmetic operator overloading (+,-,*,/)
	//add operator
	cout << "romanOne + romanTwo" << endl;
	romanTemp = romanOne + romanTwo;
	romanTemp.PrintRomanString();
	romanTemp.PrintRomanValue();
	cout << endl;
	//subtract operator
	cout << "romanOne - romanTwo" << endl;
	romanTemp = romanOne - romanTwo;
	romanTemp.PrintRomanString();
	romanTemp.PrintRomanValue();
	cout << endl;
	//multiply operator
	cout << "romanOne * romanTwo" << endl;
	romanTemp = romanOne * romanTwo;
	romanTemp.PrintRomanString();
	romanTemp.PrintRomanValue();
	cout << endl;
	//divide operator
	cout << "romanOne / romanTwo" << endl;
	romanTemp = romanOne / romanTwo;
	romanTemp.PrintRomanString();
	romanTemp.PrintRomanValue();
	cout << endl;
		
	return 0;
	
}

//*******************************************************************************************************
//*******************************************************************************************************

