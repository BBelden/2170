//************************************************************************************************************
//************************************************************************************************************
//Name:       Ben Belden
//Class ID#:  c1004202
//Section:    CSCI 2170-001
//Assignment: Open Lab Assignment #2
//Due:        00:00, February 19, 2013
//Purpose:    To read Roman numerals and an arithmetic operator from a given data file, convert the Roman 
//            numerals into Arabic numerals, perform arithmetic on the values, then convert the resulting
//            Arabic numeral integer into Roman numerals. 
//Input:      From pre-formatted data file.
//Output:     Print to terminal.

#include <iostream>		//for cin/cout
#include <string>		//for string data type
#include <fstream>		//for file stream data type
#include <cstdlib>		//for abs()

using namespace std;

//function prototypes
int Roman_to_Number (string romanNumeral);
string Number_to_Roman (int number);
int afterMath (int number1, int number2, char math);

//main function
int main ()
{
	//declaration of local variables
	ifstream myFile;		//input file stream from pre-determined input file
	string get1; 			//holds the 1st Roman numeral read from input file
	string get2;			//holds the 2nd Roman numeral read from input file
	string romanNumeral; 	//holds the Roman numeral string
	string oper;			//used to hold an output string based on arithmetic operator
	int number1;			//holds the 1st Arabic numeral after conversion
	int number2; 			//holds the 2nd Arabic numeral after conversion
	int after;				//holds the integer value after arithmetic
	char math; 				//holds the arithmetic operator character
	char end;				//used to remove end of line character
	
	myFile.open("roman.txt"); 	//open pre-formatted, given file
	
	//priming read
	myFile >> get1;				//get 1st Roman numeral
	
	//end-of-file loop
	while (myFile)
	{
		myFile.get(end);		//remove end of line character
		myFile >> get2;			//get 2nd Roman numeral
		myFile >> math;			//get arithmetic operator
		
		//function calls
		number1 = Roman_to_Number(get1);			//converts first Roman numeral to Arabic
		number2 = Roman_to_Number(get2);			//converts second Roman numeral to Arabic
		after = afterMath(number1, number2, math);	//performs arithmetic operation
		romanNumeral = Number_to_Roman(after);		//converts Arabic integer to Roman numeral

		//sets output variable based on arithmetic operator
		switch (math)
		{
			case '+' : oper = " sum of "; break;
			case '-' : oper = " difference of "; break;
			case '*' : oper = " multiplication of "; break;
			case '/' : oper = " division of "; break;
		}
		
		//output statements, print to screen
		cout << "\nThe first number is: " << number1;
		cout << "\nThe second number is: " << number2;
		cout << "\nThe arithmetic operator is: " << math;
		cout << "\nThe" << oper << number1 << " and " << number2 << " is: "<< after;
		cout << "\nwhich in Roman numeral format is: " << romanNumeral << endl << endl;
		
		//get next Roman numeral
		myFile.get (end);		//remove end of line character
		myFile >> get1;			//get 1st Roman numeral
	}
	
	myFile.close ();			//close file
	
	return 0;
	
}


//function definitions
//************************************************************************************************************

int Roman_to_Number (string romanNumeral)
//Purpose: Converts a string containing Roman numeral characters into an integer by populating a temporary
// integer array with the converted values of the character array (string), then summing appropriately.
//Precondition: Passed a string of no more than 10 characters in length.
//Postcondition: Returns the correctly converted integer value of the Roman numeral.
{
	int temp[10];			//declares an integer array and assumes that there will be up to 10 indexes used
	
	//Populates the temp array with integer values equal to the values of the Roman numerals at the same index
	for (int i = 0; i < romanNumeral.length(); i++)
	{
		if (romanNumeral[i] == 'M')
			temp[i] = 1000;
		else if (romanNumeral[i] == 'D')
			temp[i] = 500;
		else if (romanNumeral[i] == 'C')
			temp[i] = 100;
		else if (romanNumeral[i] == 'L')
			temp[i] = 50;
		else if (romanNumeral[i] == 'X')
			temp[i] = 10;
		else if (romanNumeral[i] == 'V')
			temp[i] = 5;
		else if (romanNumeral[i] == 'I')
			temp[i] = 1;
	}

	int sum = 0; 							//holds the value of the sum of each integer in the array
	int i = romanNumeral.length() - 1;		//sets the counter to the last index of the array
	//sums the values of each index in the array
	while (i >= 0)
	{
		sum = sum + temp[i];
		if (!(i+1 >= romanNumeral.length()))
			//tests for higher value to the right of the index and subtracts it from the sum
			if (temp[i] < temp[i+1])
				sum = sum - (2 * temp[i]);
		i--;
	}
	
	return sum;								//passes control back to main with the integer: sum
}

//************************************************************************************************************

string Number_to_Roman (int number)
//Purpose: Convert an integer to a Roman numeral string.
//Precondition: 0 <= number < 10000
//Postcondition: Return a string without spaces to main.
{
	int one = (number / 1) % 10;		//used to hold the value of the ones column of an integer
	int ten = (number / 10) % 10;		//used to hold the value of the tens column of an integer
	int hund = (number / 100) % 10;		//used to hold the value of the hundreds column of an integer
	int thou = (number / 1000) % 10;	//used to hold the value of the thousands column of an integer
	//holds the value of the converted Roman numeral from each integral column to be concatenated
	string temp;						
	string hold;						//used to hold the Roman numera string without spaces
	string romanNumeral;				//used to hold the concatenated Roman numeral
		
	//converts ones column into roman numeral and concatenates it to "temp"
	switch (one)
	{
		case 1 : temp = "I"; break;
		case 2 : temp = "II"; break;
		case 3 : temp = "III"; break;
		case 4 : temp = "IV"; break;
		case 5 : temp = "V"; break;
		case 6 : temp = "VI"; break;
		case 7 : temp = "VII"; break;
		case 8 : temp = "VIII"; break;
		case 9 : temp = "IX"; break;
		default : temp = " "; break;
	}
	romanNumeral = temp + romanNumeral;
	
	//converts tens column into roman numeral and concatenates it to "temp"
	switch (ten)
	{
		case 1 : temp = "X"; break;
		case 2 : temp = "XX"; break;
		case 3 : temp = "XXX"; break;
		case 4 : temp = "XL"; break;
		case 5 : temp = "L"; break;
		case 6 : temp = "LX"; break;
		case 7 : temp = "LXX"; break;
		case 8 : temp = "LXXX"; break;
		case 9 : temp = "XC"; break;
		default : temp = " "; break;
	}
	romanNumeral = temp + romanNumeral;
	
	//converts hundreds column into roman numeral and concatenates it to "temp"
	switch (hund)
	{
		case 1 : temp = "C"; break;
		case 2 : temp = "CC"; break;
		case 3 : temp = "CCC"; break;
		case 4 : temp = "CD"; break;
		case 5 : temp = "D"; break;
		case 6 : temp = "DC"; break;
		case 7 : temp = "DCC"; break;
		case 8 : temp = "DCCC"; break;
		case 9 : temp = "CM"; break;
		default : temp = " "; break;
	}
	romanNumeral = temp + romanNumeral;

	//converts thousands column into roman numeral and concatenates it to "temp"
	switch (thou)
	{
		case 1 : temp = "M"; break;
		case 2 : temp = "MM"; break;
		case 3 : temp = "MMM"; break;
		case 4 : temp = "MMMM"; break;
		case 5 : temp = "MMMMM"; break;
		case 6 : temp = "MMMMMM"; break;
		case 7 : temp = "MMMMMMM"; break;
		case 8 : temp = "MMMMMMMM"; break;
		case 9 : temp = "MMMMMMMMM"; break;
		default : temp = " "; break;
	}
	romanNumeral = temp + romanNumeral;
	
	//removes any spaces after concatenation of "temp"
	for (int i = 0; i < romanNumeral.length(); i++)
	{
		if (romanNumeral[i] != ' ')
			hold = hold + romanNumeral[i];
	}
	romanNumeral = hold;			
	
	return romanNumeral;			//passes control back to main with the string: romanNumeral
}

//************************************************************************************************************

int afterMath (int number1, int number2, char math)
//Purpose: Performs arithmetic operation on two integers based on a given operator
//Precondition: Two positive integers and one character are passed into the function.
//Postcondition: Return a positive integer.
{
	int after;						//holds the integer value after arithmetic 
	
	//performs arithmetic operation based on the value of the variable: math
	switch (math)
	{
		case '+' : after = number1 + number2; break;
		case '-' : after = number1 - number2; break;
		case '*' : after = number1 * number2; break;
		case '/' : after = number1 / number2; break;
	}
	
	after = abs(after);				//converts the integer to the absolute value of that integer
	
	return after;					//passes control back to main with the integer: after
}
	
//************************************************************************************************************
//************************************************************************************************************
