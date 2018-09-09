#include <iostream>

using namespace std;

void display( void );
bool nextVacantCell( int row, int col, int& nvcRow, int& nvcCol );

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
int row, col, nvcRow, nvcCol;	
	
int main()
{
	display();
	cout << "\nenter the row and column of the cell to test\n";
	cin >> row >> col;
	row = row-1;
	col = col-1;
	nextVacantCell(row, col, nvcRow, nvcCol);
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
	
	for (int i=row; i<9; i++)
	{
		for (int j=0; j<9; j++)
		{
			if ((m_board[i][j] == 0) && ((i == row && j > col) || (i > row)))
			{
				vacant == true;
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
