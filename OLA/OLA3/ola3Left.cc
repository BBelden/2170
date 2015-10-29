//*******************************************************************************************************
//*******************************************************************************************************
//Name:       Ben Belden
//Class ID#:  c1004202
//Section:    CSCI 2170-001
//Assignment: Open Lab Assignment #3
//Due:        24:00, March 4, 2013
//Purpose:    The purpose of this program is to take a given set of number and, starting from index 0,
//            find your way to the index that contains the 0. However, you may only move to the left or
//            right the number of indexes shown in the index that you're on. 
//            Solved using recursive function calls and a frequency array attached to the puzzle array
//            as a second row. The frequency array is used to mark indexes that have already been used.
//Input:      From pre-formatted data file.
//Output:     Print to terminal.

#include <iostream>		//for cin/cout
#include <string>		//for string data type
#include <fstream>		//for file stream data type

using namespace std;

//function prototype
bool solve (int, int, int, int puzzle[][2]);	

//main function
int main ()
{
	//declaration of local variables
	ifstream myFile;			//input file stream from pre-determined input file
	int size;					//used to hold the value of the size of the puzzle
	int start;					//used to hold the index number from which movement occurs
	int number;					//used as a puzzle number counter
	int puzzle [20][2];			//puzzle array with attached frequency array 
	
	//prints user introduction
	cout << "\nHello!\nThe purpose of this program is to take a given set of numbers\n";
	cout << "and, starting from index 0, find your way to the index that\n";
	cout << "contains the 0. However, you may only move to the left or right\n";
	cout << "the number of indexes shown in the index that you're on.\n";
	cout << "Good luck!\n";
	
	myFile.open("puzzle.txt"); 	//open pre-formatted, given file
	
	//priming read and puzzle counter initialization
	myFile >> size >> start;					
	number = 1;					
	
	//EOF loop
	while (myFile)
	{
		//reads in puzzle array
		for (int i = 0; i < size; i++)
			myFile >> puzzle[i][0];
		
		//initializes frequency array
		for (int i = 0; i < size; i++)
			puzzle[i][1] = 0;

		//prints puzzle indexes and puzzle data
		cout << "\nPuzzle " << number << "\nIndex:  "; 
		for (int i = 0; i < size; i++)
			cout << i << "\t";
		cout << "\nPuzzle: ";
		for (int i = 0; i < size; i++)
			cout << puzzle[i][0] << "\t";
		cout << endl << endl << "Start at index 0\n";
		
		if (solve (size, start, number, puzzle) == true)		//function call
			break;
		
		//get next puzzle size and start numbers and increment puzzle counter
		myFile >> size >> start;
		number++;				
	}
	
	myFile.close ();			//close file
	
	return 0;
	
}


//function definition
//*******************************************************************************************************
//Function: solve
//Purpose: 
//Precondition: 
//Postcondition: Returns to calling function when 

bool solve (int size, int start, int number, int puzzle[][2])
{	
	//tests for the goal (0) at index: start
	if (puzzle[start][0] == 0)
	{
		cout <<  "YOU'VE SOLVED PUZZLE " << number << "!\n\n";
		return true;					//passes control back to calling function
	}
	
	//uses the frequency array to test for whether the the index at puzzle[start][] has been used
	if (puzzle[start][1] > 0)
	{
		cout << "Puzzle " << number << " cannot be not solved!\n\n";
		return false;					//passes control back to calling function
	}

	//tests for ....
	if (start - puzzle[start][0] >=0 && start - puzzle[start][0] < size)
	{
		cout << "Move " << puzzle[start][0] << " places to the left to index ";
		cout << start - puzzle[start][0] << endl;					//prints path
		puzzle[start][1]++;											//increment frequency counter
		return solve(size, start - puzzle[start][0], number, puzzle);		//recursive function call
		//return;											//passes control back to calling function
	}
	
	//tests for ....
	if (start + puzzle[start][0] >= 0 && start + puzzle[start][0] < size)
	{
		cout << "Move " << puzzle[start][0] << " places to the right to index ";
		cout << start + puzzle[start][0] << endl;					//prints path
		puzzle[start][1]++;											//increment frequency counter
		return solve(size, start + puzzle[start][0], number, puzzle);		//recursive function call
		//return;											//passes control back to calling function
	}
	
							//passes control back to calling function
}
//*******************************************************************************************************
//*******************************************************************************************************
