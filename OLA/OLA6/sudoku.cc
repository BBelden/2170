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
//File:       sudoku.cc
//
//This is the implementation file for the Sudoku class.

#include "sudoku.h"		// header file
#include <iostream>		// for cin/cout
#include <stack>		// for stack

using namespace std;

// global variable declarations
struct StackItemType	// stack element
{
	int	row;	// The row index
	int	col;	// The column index
};
StackItemType topNode;  	// used to identify the top node on the stack
StackItemType pushNode; 	// used to push a node onto the stack
bool bPotential[SUDOKU_SIZE];   // used to mark potential values for puzzle cells
int value[SUDOKU_SIZE];         // used to help find potential values for puzzle cells
int size;               	// used to show the number of values in value[]
int row, col;           	// for row/col of the sudoku puzzle board
int nvcRow, nvcCol;     	// for row/col in next vacant cell

// *******************************************************************************************************

// this method loads the puzzle into m_board[][]
// pre-condition: 	file opened and read first puzzle, passed into method
// post-condition: 	m_board[][] is loaded
void Sudoku::load( int cells[][SUDOKU_SIZE] )
{
	for (int i = 0; i <= 8; i++)
		for (int j = 0; j <= 8; j++)
			m_board[i][j] = cells[i][j];
} // end load

// *******************************************************************************************************

// this method displays puzzle board in the following format:
// # # # | # # # | # # #
// # # # | # # # | # # #
// # # # | # # # | # # #
// ---------------------
// # # # | # # # | # # #
// # # # | # # # | # # #
// # # # | # # # | # # #
// ---------------------
// # # # | # # # | # # #
// # # # | # # # | # # #
// # # # | # # # | # # #
// pre-condition: 	m_board[][] is loaded
// post-condition: 	m_board[][] is printed to terminal
void Sudoku::display( void )
{
	for (int i = 0; i <= 8; i++) {
		for (int j = 0; j <= 8; j++) {
			if (j >=3 && j%3 == 0)
				cout << "| "<< m_board[i][j]<< " ";
			else
				cout << m_board[i][j] << " ";
		} // end for - column
		if (i < 8 && i%3 == 2)
			cout << "\n---------------------\n";
		else
			cout << endl;
	} // end for - row
} // end display

// *******************************************************************************************************

// This method solves a loaded sudoku puzzle using brute force. It finds the first vacant cell, pushes 
// that position (row, col) to the stack, tests for all potential solutions, enters the lowest potential 
// solution, then goes on to the next vacant cell. It repeats this process until there is no potential 
// solution for the current cell, pops the top node on the stack and goes back to the last cell that was
// tested and will then test the next highest potential solution value. It will continue this until 
// either a solution is found, or the stack is emptied which means that there is no solution to the 
// loaded puzzle. 
// pre-condition: 	m_board[][] is loaded
// post-condition: 	returns true if a solution is found. returns false if no solution.

bool Sudoku::solve( void )
{
	stack<StackItemType> s; 	// initialize standard library stack
	bool solved = false;    	// bool flag passed out of method
    
	// get next vacant cell starting at cell position 0,0 and push the vacant position to the stack
	nextVacantCell(0,0, pushNode.row, pushNode.col);
	s.push(pushNode);		

	while (!s.empty()) {

		// get cell position values from the top node and reference those values to find
		// potential solution values 
		topNode = s.top(); 
		row = topNode.row;
		col = topNode.col;
		potentialValues(row, col, size);
  
		for (int i = m_board[row][col] - 1; i<9; i++) {
			// if the next highest potential solution value exists as indicated by bPotential[], 
			// change cell value in m_board[row][col].
			if (i + 1 > m_board[row][col] && bPotential[i] == true) {
				m_board[row][col] = i + 1;		
				
				//  if a potential solution value is found, and no more vacant cells exist, return
				// true. else push the cell position of the next vacant cell to the stack and 
				// break out of the for loop
				if (!nextVacantCell(row, col, pushNode.row, pushNode.col)) {
					solved = true;
					return solved;
				} // end if
				else
					s.push(pushNode); 
				break;
			} // end if
			
			// if the for loop reaches the highest value of i and no potential solution value is found,
			// pop the top stack node
			else if (i == 8 && bPotential[i] == false) {
				m_board[row][col] = 0;
				s.pop();
			} // end else
		} // end for
	} // end while    
    return solved;		// returns false if the stack is empty
} // end solve

// *******************************************************************************************************

// private method implementation

// This function find the first vacant cell starting at the cell (row, col). If there is a vacant cell, 
// return true, otherwise return false. Attention: the cell (row, col) may be the first vacant cell.
// pre-condition: 	m_board[][] is loaded and a cell position is passed in
// post-condition: 	if a vacant cell is found, update nvcRow and nvcCol and return true. otherwise, 
// 					return false. 

bool Sudoku::nextVacantCell( int row, int col, int& nvcRow, int& nvcCol )
{
    bool vacant = false; 	// sets return flag. 
		
	// tests for next vacant cell starting at col 0 in the row passed into the method. if a vacant cell
	// is found, return true
	for (int i=row; i<9; i++) {
		for (int j=0; j<9; j++) {
			if (m_board[i][j] == 0) {
				vacant = true;
				nvcRow = i;
				nvcCol = j;
				return vacant;
			} // end if
		} // end for
	} // end for

	return vacant; 		// otherwise return false
} // end nextVacantCell

// *******************************************************************************************************

// This function gets all potential values for the specified cell. A potential value for a cell is a 
// value that doesn't appear in the same block, the same row, and the same column in the current board.
// pre-condition:	The parameter size is the size of the array values, and
//					0 <= row, col < Sudoku_SIZE && size == 9
// post-condition:	The array values contains the potential values for the cell (row, col) and the 
//					parameter size is the number of potential values

void Sudoku::potentialValues( int row, int col, int& size )
{
	// initializes bPotential[] to true
	for (int i = 0; i<9; i++)
		bPotential[i] = true;
	
	// from a given cell, get all non-solution values from the row and column, change the corresponding 
	// index to false in bPotential[]
	for (int i = 0; i<9; i++) {
		if (m_board[row][i] != 0)
			bPotential[m_board[row][i] - 1] = false;
		if (m_board[i][col] != 0)
			bPotential[m_board[i][col] - 1] = false;
	} // end for
    
	// get all non-solution values from the sub block, change the corresponding index to false
	getBlockValues(subBlock(row,col), value, size);
    for (int i = 0; i < size; i++)
		bPotential[value[i]-1] = false;

	return;
} // end potentialValues

// *******************************************************************************************************

// The following two method implementations were provided by Dr. Yoo.

// This function calculates the index of the block containing the cell
// (row, col). The following figure lists the index of blocks in the game.
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
// pre-condition:	0 <= row, col < 9
// post-condition:	return value is in [1, 9].
int Sudoku::subBlock( int row, int col )
{
	int		arrayIndex;
    
    if ( row < 3 )
		arrayIndex = col/3 + 1;
	else if ( row < 6 )
		arrayIndex = col/3 + 4;
	else
		arrayIndex = col/3 + 7;
	return arrayIndex;
} // end subBlock

// *******************************************************************************************************

// This function returns all non-zero values the player gets so far in
// the given block.
// These values are saved in the array value. The parameter size is the
// number of non-zero values in the block.
// pre-condition:	size == 9 && 1 <= subBlock <= 9
// post-condition:	The array value contains all values in the specified block
//				    and size is the number of non-zero values in the sub-array
void Sudoku::getBlockValues( int subBlock,	// in only
                            int value[],		// out only
                            int& size )			// in & out
{
	int		beginRow, endRow;
	int		beginCol, endCol;
    
	int		rem = (subBlock - 1) / 3;
    
	beginRow = rem*3;
	endRow = rem*3 + 2;
    
	rem = subBlock % 3;
	if ( rem == 0 )
		rem = 3;
	beginCol = (rem -1)*3;
	endCol = 3*rem - 1;
    
	size = 0;
	for ( int i=beginRow; i<=endRow; i++ )
		for ( int j=beginCol; j<=endCol; j++ )
			if ( m_board[i][j] != 0 )
				value[size++] = m_board[i][j];
	return;
} // end getBlockValues

// *******************************************************************************************************

