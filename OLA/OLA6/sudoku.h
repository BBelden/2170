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
//File:       sudoku.h
//
//This is the header file for the Sudoku class.

#ifndef _SUDOKU_H
#define _SUDOKU_H

const int SUDOKU_SIZE = 9;

class Sudoku
{
public:
	// Create a sudoku game by initializing m_board[][] based on a given array in the 
	// following format.
	//	8 2 0 | 0 0 5 | 4 0 9
	//	0 0 4 | 0 0 0 | 0 7 3
	//	0 0 7 | 0 6 0 | 0 0 1
	//	---------------------
	//	0 0 0 | 0 0 2 | 0 0 0
	//	4 7 6 | 1 8 9 | 3 5 2
	//	0 0 0 | 6 0 0 | 0 0 0
	//	---------------------
	//	7 0 0 | 0 1 0 | 2 0 0
	//	9 4 0 | 0 0 0 | 1 0 0
	//	5 0 3 | 8 0 0 | 0 4 6
	// The value 0 represents the position that the player needs to fill.
	void load( int cells[][SUDOKU_SIZE] );
    
	// Find a solution for the current sudoku game. If a solution is
	// found, return true. If there is no solution for the game, return false.
	bool solve( void );
    
	//Display the board.
	void display( void );
    
private:
	// This function find the first vacant cell starting at the cell (row, col). If there is a 
	// vacant cell, return true, otherwise return false. ttention: the cell (row, col) may be the 
	// first vacant cell
	bool nextVacantCell( int row, int col, int& nfcRow, int& nfcCol );
    
	// This function gets all potential values for the specified cell. A potential value for a cell 
	// is a value that doesn't appear in the same block, the same row, and the same column in the 
	// current sudoku game.
	// For example, for the cell (0,3) in the above Sudoku, the potential values should be: 3 and 7 
	// because other values either occur at the row 0, or col 3, or in the 2nd block.
	// pre-cond:	The parameter size is the size of the array values, and
	//				0 <= row, col < Sudoku_SIZE && size == 9
	// post-cond:	The array values contains the potential values for the
	//              cell (row, col) and the parameter size is the number of
	//              potential values
	void potentialValues( int row, int col, int &size );


	// The following two functions are provided by the instructor.
    
	// This function calculates the index of the block containing the cell (row, col). The 
	// following figure lists the index of blocks in the game.
	//     1 1 1 | 2 2 2 | 3 3 3
	//     1 1 1 | 2 2 2 | 3 3 3
	//     1 1 1 | 2 2 2 | 3 3 3
	//     ---------------------
	//     4 4 4 | 5 5 5 | 6 6 6
	//     4 4 4 | 5 5 5 | 6 6 6
	//     4 4 4 | 5 5 5 | 6 6 6
	//     ---------------------
	//     7 7 7 | 8 8 8 | 9 9 9
	//     7 7 7 | 8 8 8 | 9 9 9
	//     7 7 7 | 8 8 8 | 9 9 9
	// pre-cond:	0 <= row, col < 9
	// post-cond:	return value is in [1, 9].
	int subBlock( int row, int col );
    
	// This function returns all non-zero values the player gets so far in the given block.
	// These values are saved in the array value. The parameter size is the
	// number of non-zero values in the block.
	// pre-cond:	size == 9 && 1 <= subBlock <= 9
	// post-cond:	The array value contains all values in the specified block
	//				and size is the number of non-zero values in the sub-array
	void getBlockValues( int block, int value[], int& size );
   
private:
	// the array holding the value at the sudoku game
	int     m_board[SUDOKU_SIZE][SUDOKU_SIZE];
};
#endif
