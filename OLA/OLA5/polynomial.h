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
//File:       polynomial.h
//
//This is the specification (header) file for the Polynomial class.


#include <string>
using namespace std;

//prevent multiple inclusions
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

struct Term
{
	int coeff;
	int deg;
};

class Polynomial		// an ordered linear linked list
{

friend ostream& operator << (ostream& cout, const Polynomial& rhs); // overloaded operator
	
public:

	Polynomial ();					// default constructor
	Polynomial (const Polynomial& poly);	// copy constructor
	~Polynomial();					// destructor

	struct ListNode					
	{
		Term term;					
		ListNode *next;				
	};
	
	void addTerm(Term newTerm);					// adds a node to an ordered list
	void add (const Polynomial& rhs);			// adds two Polynomial objects together in order
	bool operator == (const Polynomial& rhs);	// overloaded operator
	
private:
	// methods
	void clean ();						// removes terms whose coefficient is 0
	void remove (ListNode *badNode); 	// removes a targeted node from the list
	void insert(Term newTerm);			// inserts a node to the list

	// data members
	ListNode *head;						
};

#endif

//*******************************************************************************************************
//*******************************************************************************************************
