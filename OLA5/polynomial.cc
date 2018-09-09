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
//Input:      From standard input.
//Output:     Print to terminal.
//File:       polynomial.cc
//
// This is the implementation file for the Polynomial class


#include "polynomial.h"	// class header file
#include <iostream>		// for cin/cout
#include <string>		// for string data type

using namespace std;

// Public method implementation

// Method: default constructor
// Purpose: default constructor
// Precondition: none
// Postcondition: list has one node and its values are 0 and NULL
Polynomial::Polynomial()
{
	head = new ListNode;
	head->term.coeff = 0;
	head->term.deg = 0;
	head->next = NULL;
} // end default constructor

//*******************************************************************************************************
// Method: copy constructor
// Purpose: makes a deep copy of reference list
// Precondition: reference list is passed to method
// Postcondition: new list identical to reference list
Polynomial::Polynomial(const Polynomial& poly)
{
	if (poly.head == NULL)
		head = NULL; // original list is empty
	else {  
		// copy first node
		head = new ListNode;
		head->term = poly.head->term;

		// copy rest of list
		ListNode *newPtr = head; // new list pointer
		// newPtr points to last node in new list
		// origPtr points to nodes in original list
		for (ListNode *origPtr = poly.head->next;
                   origPtr != NULL;
                   origPtr = origPtr->next) {
			newPtr->next = new ListNode;
			newPtr = newPtr->next;
			newPtr->term = origPtr->term;
		} // end for
		newPtr->next = NULL;
	} // end if
} // end copy constructor

//*******************************************************************************************************
// Method: destructor
// Purpose: end of scope list destructor
// Precondition: none
// Postcondition: complete destruction of list, all memory deallocated
Polynomial::~Polynomial()
{
	ListNode *p;				// pointer for *this list
	p = head;					// sets p to *this list head
	// reassigns head and deletes p until head == NULL
	while (head != NULL) {
		head = head->next;
		p->next = NULL;
		delete p;
		p = head;
	} // end while
} // end destructor

//*******************************************************************************************************
// Method: addTerm
// Purpose: adds a reference term as a node to *this list
// Precondition: 
// Postcondition:
void Polynomial::addTerm(Term newTerm)		
{
	ListNode *p;			// pointer for *this list
	p = head;				// sets p to *this list head
	bool added = false;		// flag 
	
	// tests for whether the degrees are the same and if they are the coefficients are added
	while (p != NULL) {
		if (p->term.deg == newTerm.deg) {
			p->term.coeff = p->term.coeff + newTerm.coeff;
			added = true;
			clean(); // removes any terms with coefficient of 0
			return; // returns control to calling function
		} // end if
		else
			p = p->next;
	} // end while

	// calls insert method to insert term as node to *this list
	if (added == false) {
		insert(newTerm); 
		added == true;
		clean(); // removes any terms with coefficient of 0 
		return;	// returns control to calling function
	} // end if
} // end addTerm
	
//*******************************************************************************************************
// Method: add
// Purpose: add two lists together
// Precondition: both lists are ordered
// Postcondition: added reference list in order to *this list and removed any coefficients of 0
void Polynomial::add (const Polynomial& rhs)
{
	Polynomial::ListNode *r;		// pointer for reference list 
	r = rhs.head;					// sets r to reference list head
	
	// adds each node in reference list one at a time to *this list 
	while (r != NULL) {
		addTerm(r->term);
		r = r->next;
	} // end while
	return;
} // end add

//*******************************************************************************************************
// Method: == 
// Purpose: overload ==
// Precondition: *this list and reference list are ordered
// Postcondition: returns true if lists are identical
bool Polynomial::operator == (const Polynomial& rhs)
{
	bool equal = false; 
	Polynomial::ListNode *r;	// pointer for reference list 
	r = rhs.head;				// sets r to reference list head
	ListNode *p;				// pointer for *this list
	p = head;					// sets p to *this list head
	
	// test for whether each node in *this list is identical to reference list 
	while (p != NULL) {
		if (p->term.coeff == r->term.coeff && p->term.deg == r->term.deg) {	
			if (p->next == NULL && r->next == NULL) {
				equal = true;
				return equal; // return true
			} // end if
			p = p->next;  // increment *this pointer
			r = r->next;  // increment reference pointer
		} // end if
		else
			return equal; // return false
	} // end while loop
} // end ==

//*******************************************************************************************************
// Method: << 
// Purpose: overload <<
// Precondition: *this list is ordered and all coefficients of 0 have been removed
// Postcondition: prints to terminal. all X^1 print as X, all X^0 only print coefficients
ostream& operator << (ostream& cout, const Polynomial& rhs)
{
    Polynomial::ListNode *r;		// pointer for reference list
	r = rhs.head; 					// sets r to reference list head

    
   if ( r == NULL )
        cout << 0 << endl;
    else {   // output the first node
        if (r->term.deg == 0 && r->term.coeff == 0)
			cout << 0 << endl;
		else if (r->term.coeff == 1) {
			if (r->term.deg == 1)
				cout << "X";
			else if (r->term.deg == 0)
				cout << r->term.coeff;
			else 
				cout << "X^" << r->term.deg;
		}  // end else if
		else if (r->term.coeff == -1) {
			if (r->term.deg == 1)
				cout << "-X";
			else if (r->term.deg == 0)
				cout << r->term.coeff;
			else 
				cout << "-X^" << r->term.deg;
		}  // end else if
		else if (r->term.deg == 0)
			cout << r->term.coeff;
		else if (r->term.deg == 1)
			cout << r->term.coeff << "X";
		else
			cout << r->term.coeff << "X^" << r->term.deg;
		
       // output the rest of the polynominal
        for(r=r->next; r!= NULL; r=r->next ) {
            if (r->term.coeff > 0) {
                cout << " + ";
				if (r->term.deg == 0 && r->term.coeff == 0) 
					cout << 0 << endl;
				else if (r->term.coeff == 1) {
					if (r->term.deg == 1)
						cout << "X";
					else if (r->term.deg == 0)
						cout << r->term.coeff;
					else 
						cout << "X^" << r->term.deg;
				}  // end else if
				else if (r->term.deg == 0)
					cout << r->term.coeff;
				else if (r->term.deg == 1)
					cout << r->term.coeff << "X";
				else
					cout << r->term.coeff << "X^" << r->term.deg;
			} // end if
            else {
                cout << " - ";
				if (r->term.deg == 0 && r->term.coeff == 0) 
					cout << 0 << endl;
				else if (r->term.coeff == -1) {
					if (r->term.deg == 1)
						cout << "X";
					else if (r->term.deg == 0)
						cout << (-1)*(r->term.coeff);
					else 
						cout << "X^" << r->term.deg;
				}  // end else if
				else if (r->term.deg == 1)
					cout << r->term.coeff << "X";
				else if (r->term.deg == 0)
					cout << (-1)*(r->term.coeff);
				else
					cout << (-1)*(r->term.coeff) << "X^" << r->term.deg;
			}  // end else
        } // end for loop
        cout << endl;
    } // end else

    return cout;
} // end <<


//*******************************************************************************************************

// Private method implementation

// Method: clean
// Purpose: remove any node that has a coefficient of 0
// Precondition: *this list is ordered
// Postcondition: *this list has no nodes with coefficients of 0
void Polynomial::clean ()
{
	ListNode *p;				// pointer for *this list
	p = head;					// sets p to *this list head
	//tests for any node that has a coefficient of 0 and removes it
	while (p != NULL) {
		if (p->term.coeff == 0)
			remove(p);
		p = p->next;
	} // end while loop
	return;
} // end clean

//*******************************************************************************************************
// Method: remove
// Purpose: removes a reference node
// Precondition: *this list is ordered
// Postcondition: badNode removed
void Polynomial::remove (ListNode *badNode)
{
	ListNode *p;				// pointer for *this list
	p = head;					// sets p to *this list head
	ListNode *q;				// pointer for reference node
	q = badNode;				// sets q to *badNode
	
	// removes reference node
	while (p != NULL) {
		// removes node if badNode is the only node in list
		if (head->next == NULL) {
			head->term.deg = 0;
			head->term.coeff = 0;
		} // end if
		// removes node if badNode is the head
		else if (q == head) {
			head = head->next;
			p->next = NULL;
			delete p;
		} // end else
		// removes badNode
		else if (p->next == q) {
			p->next = q->next;
			q->next = NULL;
			delete q;
		} // end else if
		else
			;
		p = p->next;			// traverse to next node
	} // end while loop
	return;
} // end remove

//*******************************************************************************************************
// Method: insert
// Purpose: used to insert reference term as a node into an ordered list
// Precondition: list is ordered, node is passed in
// Postcondition: node is inserted in order to *this list
void Polynomial::insert(Term newTerm)
{
	ListNode *p;				// primary pointer for *this list
	p = head;					// sets p to *this list head
	ListNode *q;				// pointer to trail primary 
	q = head;					// sets q to *this list head
	ListNode *newNode;			// pointer to new node
	newNode = new ListNode;		// allocate new node
	newNode->term = newTerm;	// copy contents of reference term
	newNode->next = NULL;		

	// inserts newNode as the head of *this list
	if (newNode->term.deg > p->term.deg) {
		newNode->next = head;
		head = newNode;
	} // end if
	//inserts newNode in order in *this list
	else {
		p = p->next;
		while (p != NULL && newNode->term.deg < p->term.deg) {
			q = p;
			p = p->next;
		} // end while loop
		q->next = newNode;
		newNode->next = p;
	} // end else
} // end insert

//*******************************************************************************************************
//*******************************************************************************************************