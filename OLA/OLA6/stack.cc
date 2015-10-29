#include <iostream>
#include <stack>

using namespace std;
struct StackItemType
{
	int			row;	// The row index
	int			col;	// The column index
};

struct StackNode
{
	StackItemType	item;
	StackNode		*next;
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
	};
int row, col, nvcRow, nvcCol;	
typedef StackNode* NodePtr;
bool bPotential[aSize];
int iPotential[aSize] = {1, 2, 3, 4, 5, 6, 7, 8, 9};










int main()
{
	//StackItemType top;
	for (int i=0; i < 5; i++)
	{
		StackItemType push;
		push.row = i; 
		push.col = i;
		s.push(push);
		
	}
	while (!s.empty())
	{
		StackItemType top;
		top = s.top();
		cout << top.row << " " << top.col << endl;
		s.pop();
	}

	
	return 0;
}