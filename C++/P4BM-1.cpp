//This program is designed to find the names of the students in an input file 
//and alphabatize them to find out who goes first and last in the line
//Bradley Melchor
//COP2000.CM1
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{

	ifstream inputFile;     
	int counter = 0;	// loop needs a counter otherwise would keep rereading the same data or not execute at all.
	string name;		// used as a variable to catch data from the input file
	string firstName;	// variable to capture first name
	string lastName;	// variable to capture the last name 

	//Attempts to open input file
	inputFile.open("lineUP.txt");

	if (inputFile.fail())
		cout << "Error opening input file. \n"
	else {

	}

	while (inputFile >> name )	// when data/value is identified it starts the loop
	{ 
		if (counter == 0)
		{
			firstName = name;	// captures first name to be compared
			lastName = name;	// capturess second name to be compared
			counter++;
		}
		else
		{ 
			if (name < firstName)		// the conditions listed below compares ASCII values and compares them
				firstName = name;		// if a name is less than firstName value it picks up the lesser value
			else if (name > lastName)   // captures higher value name
				lastName = name;
		}
	}
	inputFile.close();			//closes the file 
		cout << "First student in line is " << firstName << endl;
	cout << "Last student in line is " << lastName << endl;			//shows results for the names at the front and end of the line.

	return 0;
}