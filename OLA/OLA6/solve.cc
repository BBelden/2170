#include <iostream>
#include <stack>

using namespace std;
struct StackItemType
{
	int			row;	// The row index
	int			col;	// The column index
};

stack<StackItemType> s;

void display( void );
bool nextVacantCell( int row, int col, int& nvcRow, int& nvcCol );
void potentialValues( int row, int col, int values[], int& size );
int subBlock( int row, int col );
void getBlockValues( int subBlock, int value[], int& size );

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
};/*
bool m_vacant [aSize][aSize] = 
{
	{false, false, true, true, true, false, false, true, false},
	{true, true, false, true, true, true, true, false, false},
	{true, true, false, true, false, true, true, true, false},
	{true, true, true, true, true, false, true, true, true},
	{false, false, false, false, false, false, false, false, false},
	{true, true, true, false, true, true, true, true, true},
	{false, true, true, true, false, true, false, true, true},
	{false, false, true, true, true, true, false, true, true},
	{false, true, false, false, true, true, true, false, false}
};

int m_board[aSize][aSize] =
{
	{1, 2, 3, 4, 5, 6, 7, 8, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 2},
	{0, 0, 0, 0, 0, 0, 0, 0, 3},
	{0, 0, 0, 0, 0, 0, 0, 0, 4},
	{0, 0, 0, 0, 0, 0, 0, 0, 5},
	{0, 0, 0, 0, 0, 0, 0, 0, 6},
	{0, 0, 0, 0, 0, 0, 0, 0, 7},
	{0, 0, 0, 0, 0, 0, 0, 0, 8},
	{0, 0, 0, 0, 0, 0, 0, 0, 9}
};
/*bool m_vacant [aSize][aSize] = 
{
	{false, false, false, false, false, false, false, false, true},
	{true, true, true, true, true, true, true, true, false},
	{true, true, true, true, true, true, true, true, false},
	{true, true, true, true, true, true, true, true, false},
	{true, true, true, true, true, true, true, true, false},
	{true, true, true, true, true, true, true, true, false},
	{true, true, true, true, true, true, true, true, false},
	{true, true, true, true, true, true, true, true, false},
	{true, true, true, true, true, true, true, true, false}
};
	*/
int row, col, nvcRow, nvcCol;
StackItemType topNode, pushNode;
bool bPotential[aSize];
int iPotential[aSize] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
bool vacant;









int main()
{
	display();
	
	int size = 9;
	int value[aSize] = {0};
	int index;
	//topNode = new StackNode;
	//topNode.next = NULL;
	nextVacantCell(0,0, pushNode.row, pushNode.col);
	s.push(pushNode);
	while (!s.empty())
	{
		cout << "stack:\n";
		topNode = s.top();
		row = topNode.row;
		col = topNode.col;
		potentialValues(row, col, value, size);
        index = m_board[row][col];
		for (int i = index; i<9; i++)
		{
			if (iPotential[i] > m_board[row][col] && bPotential[i] == true)
			{
				index = i;
				break;
			}
		}
		if (iPotential[index] > m_board[row][col] && bPotential[index] == true)
		{
			m_board[row][col] = iPotential[index];
			//vacant = nextVacantCell(row, col, pushNode.row, pushNode.col);
            if (!nextVacantCell(row, col, pushNode.row, pushNode.col))
			{
				cout << "\nsolution\n\n";
				display();
                cout << endl;
                return 1;
			}
			else
			{
				s.push(pushNode);
				cout << "pushing to stack\n";
			}
		}
		else
		{
			m_board[row][col] = 0;
			cout << "popping from stack\n";
			s.pop();
		}
		display();
	}
	cout << "stack is empty\n";
	return 0;
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

bool nextVacantCell( int row, int col, int& nvcRow, int& nvcCol )
{
    bool vacant = false;
	
	if (m_board[row][col] == 0) /*(m_vacant[row][col] == true)*/
    {
        nvcRow = row;
        nvcCol = col;
        vacant = true;
        return vacant;
    }
    else
        ;
    for (int i=row; i<9; i++)
	{
		for (int j=0; j<9; j++)
		{
			if ((m_board[i][j] == 0) /*&& m_vacant[i][j] == true */&& ((i == row && j > col) || (i > row)))
			{
				vacant = true;
				nvcRow = i;
				nvcCol = j;
				cout << "next vacant cell is: " << nvcRow+1 << " " << nvcCol+1 << endl;
				return vacant;
			}
		}
	}
	nvcRow = -1;
	nvcCol = -1;
	cout << "no more vacant cells" << endl;
	return vacant;
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
    if (row == -1)
        return;
	//initializes reference array
	if (m_board[row][col] == 0)
	{
		for (int i = 0; i<9; i++)
			bPotential[i] = true;
	}
	else if (row == topNode.row && col == topNode.col)
	{
		for (int i = 0; i < m_board[row][col]; i++)
			bPotential[i] = false;
        for (int i = m_board[row][col]; i<9; i++)
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
     cout << "\ntesting subBlock\n";
     cout << "available numbers:";
    
	getBlockValues(subBlock(row,col), value, size);
    
	for (int i = 0; i < size; i++)
		bPotential[value[i]-1] = false;
	for (int i = 0; i < 9; i++)
		if (bPotential[i] == true)
			cout << iPotential[i];
	cout << endl << endl;
    /*
     for (int i = 0; i<9; i++)
     if (bPotential[i] = true)
     value[
     */
}
