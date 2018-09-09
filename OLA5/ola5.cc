//*******************************************************************************************************
//*******************************************************************************************************
//Name:       Ben Belden
//Class ID#:  c1004202
//Section:    CSCI 2170-001
//Assignment: Open Lab Assignment #5
//Due:        00:00, April 8, 2013
//Purpose:    This program creates a polynomial class utilzing linear linked lists, where each term of 
//            the polynomial is a node in the linked list and the degrees and coefficents are members 
//			  of each node. The user will input the degrees and coefficients of two polynomials via 
//            standard input. The polynomials will be ordered by degree from highest to lowest. A deep 
//            copy will be made of the first input polynomial to create a third polynomial. The second 
//            polynomial will be added to the third polynomial and the sum will be output to the 
//            terminal.
//Input:      From hard coded data and standard input.
//Output:     Print to terminal.
//File:       ola5.cc
//
//This is the client file for the Polynomial class

#include "polynomial.h"	//class header file
#include <iostream>		//for cin/cout
#include <string>		//for string data type

using namespace std;

//Read one polynomial from screen
void readOnePolynomial(Polynomial& poly)
{
	Term term;
	cout << "Enter coefficients and degrees of the polynominal." << endl
	<< "The polynominal ends if both coefficient and degree are 0" << endl << endl << endl;
	cout << "Coefficient \t Degree of Terms" << endl;
	cin >> term.coeff >> term.deg;
	while ( term.coeff != 0 || term.deg != 0 ) {//0 0 signals end of term
		poly.addTerm(term);
		cin >> term.coeff >> term.deg;
	} // end while loop
	return;
}

int main()
{
	//Declare polynomial objects
	Polynomial poly1, poly2; //default constructor
	//read polynomials
	readOnePolynomial(poly1);
	cout << poly1;
	readOnePolynomial(poly2);
	cout << poly2;
	if (poly1 == poly2)
		cout << "These two polynomials are equal to each other!" << endl;
	else
		cout << "These two polynomials are NOT equal to each other!" << endl;
	// make a deep copy of poly1
	Polynomial poly3(poly1);
	// add poly2 to poly3
	poly3.add(poly2);
	cout << "  " << poly1
	<< "+   " << poly2;
	cout << " ________________________________________" << endl
	<< " " << poly3 << endl;
	return 0;
} // end main

//*******************************************************************************************************
//*******************************************************************************************************

