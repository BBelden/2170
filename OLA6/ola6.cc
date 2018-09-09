// *******************************************************************************************************
// *******************************************************************************************************
//Name:       Ben Belden
//Class ID#:  c1004202
//Section:    CSCI 2170-001
//Assignment: Open Lab Assignment #6
//Due:        00:00, April 24, 2013
//Purpose:    Read in sudoku puzzles from a text file. Load them into the class and solve the puzzle, 
//            outputting to terminal. This is an exercise in using STL stacks.
//Input:      From pre-formatted data file.
//Output:     Print to terminal.
//
//File:       ola6.cc
//
//This is the client file for the Sudoku class.

#include "sudoku.h"     // header file
#include <iostream>		// for cin/cout
#include <string>		// for string data type
#include <fstream>		// for file stream data type

using namespace std;

//main function
int main ()
{
    //declaration of local variables
	ifstream myFile;			//input file stream from pre-determined input file
	int board [SUDOKU_SIZE][SUDOKU_SIZE];   //initialize game board array
	Sudoku game;    // instance of Sudoku class
	myFile.open("sudoku.txt"); 	//open pre-formatted, given file
	int g = 1; // puzzle counter
	
    // priming read, first puzzle
	for (int i = 0; i <= 8; i++) {
		for (int j = 0; j <= 8; j++) {
			myFile >> board[i][j];
		} // end for - column
	} // end for - row
    
	while (myFile) {
		cout << "Puzzle " << g << " loaded:\n";

        game.load(board); // load read puzzle into class member
 
        game.display(); // display new, unsolved puzzle
		
		if (game.solve()) {
			cout << "\nPuzzle " << g << " solved:\n";
			game.display(); // display solved puzzle
			cout << endl << endl;
		} // end if
		else 
			cout << "\nPuzzle " << g << " is unsolvable. :-(\n\n";
        
		g++; // increment puzzle counter
        
        // read next puzzle
		for (int i = 0; i <= 8; i++) {
            for (int j = 0; j <= 8; j++) {
                myFile >> board[i][j];
            } // end for - column
        } // end for - row
        
	} // end while
	myFile.close ();			//close file
	
	return 0;
	
} // end main
