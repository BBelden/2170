#include <iostream>

using namespace std;

int subBlock( int row, int col );
void getBlockValues( int subBlock, int value[], int& size );
void potentialValues( int row, int col, int values[], int& size );
void display( void );

const int aSize = 9;
int m_board[aSize][aSize] =
	{
		{8, 2, 0, 0, 0, 5, 4, 0, 9},
		{0, 0, 4, 0, 0, 0, 0, 7, 3},
		{0, 0, 7, 0, 6, 0, 0, 0, 1},
		{0, 0, 0, 0, 0, 2, 0, 0, 0},
		{4, 7, 6, 1, 8, 9, 3, 5, 2},
		{0, 0, 0, 6, 0, 0, 0, 0, 0},
		{7, 0, 0, 0, 1, 0, 2, 0, 0},
		{9, 4, 0, 0, 0, 0, 1, 0, 0},
		{5, 0, 3, 8, 0, 0, 0, 4, 6}
	};
bool bPotential[aSize];
int iPotential[aSize] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
int row, col, nfcRow, nfcCol;	
	
int main()
{
	display();
	cout << "\nenter the row and column of the cell to test\n";
	cin >> row >> col;
	row = row-1;
	col = col-1;
	int size = 9;
	int value[aSize] = {0};
	potentialValues( row, col, value, size );
	return 0;
}


int subBlock( int row, int col )
{
	int		arrayIndex;
    
    if ( row < 3 )
		arrayIndex = col/3 + 1;
	else if ( row < 6 )
		arrayIndex = col/3 + 4;
	else
		arrayIndex = col/3 + 7;
	return arrayIndex;
}

// This function returns all non-zero values the player gets so far in
// the given block.
// These values are saved in the array value. The parameter size is the
// number of non-zero values in the block.
// pre-cond:	size == 9 && 1 <= subBlock <= 9
// post-cond:	The array value contains all values in the specified block
//				and size is the number of non-zero values in the sub-array
void getBlockValues( int subBlock,	// in only
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
}

void potentialValues( int row, int col, int value[], int& size )
{
 	cout << "row " << row+1 << ", col " << col+1 << endl;
 	cout << "\nsub block: " << subBlock(row, col) << endl;
  
	//initializes reference array
	if (m_board[row][col] == 0)
	{
		for (int i = 0; i<9; i++)
			bPotential[i] = true;
	}
	else
	{
		for (int i = 0; i<9; i++)
			bPotential[i] = false;
	}
	
	cout << "\ntesting row and column\n";

	for (int i = 0; i<9; i++)
	{
		if (m_board[row][i] != 0)
			bPotential[m_board[row][i] - 1] = false;
		if (m_board[i][col] != 0)
			bPotential[m_board[i][col] - 1] = false;
	}	
	cout <<"available numbers: ";
	for (int i = 0; i < 9; i++)
	{
		if (bPotential[i] == true)
			cout << iPotential[i];
	}
	cout << "\ntesting subBlock\navailable numbers:";

	getBlockValues(subBlock(row,col), value, size);

	for (int i = 0; i < size; i++)
		bPotential[value[i]-1] = false;
	for (int i = 0; i < 9; i++)
		if (bPotential[i] == true)
			cout << iPotential[i];
	cout << endl << endl;
}

void display( void )
{
	for (int i = 0; i <= 8; i++)
	{
		for (int j = 0; j <= 8; j++)
		{
			if (j >=3 && j%3 == 0)
				cout << "| "<< m_board[i][j]<< " ";
			else
				cout << m_board[i][j] << " ";
		}
		if (i < 8 && i%3 == 2)
			cout << "\n---------------------\n";
		else
			cout << endl;
	}
}
