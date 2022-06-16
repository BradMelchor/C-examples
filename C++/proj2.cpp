//Brad Melchor
//Cop2000.cm1
//this program generates random numbers to be solved
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	const int max_Value = 999; //max value of the numbers
	const int min_Value = 100; // min value of the numbers
	int num1;				   // first number from random generator
	int num2;				   // second number from random generator
	int answer;				   // first number + second number
	char ch;
	int seed;
	

		//generates 2 random numbers within the max and min values (999-100)
	seed = time(0);
		srand(seed);

	num1 = (rand() % (max_Value - min_Value + 1)) + min_Value;
	cout << " " << num1;
	num2 = (rand() % (max_Value - min_Value + 1)) + min_Value;
	cout << "\n+" << num2;													//gives format to program with \n
	
	cout << "\n----";												//gives a pause so student can do problem then answer it before seeing answer
	ch= cin.get();
		
	answer = num1 + num2;													//shows the answer and gives a pause before closing out program
	cout << answer;
	ch = cin.get();
	cout << endl;
	
	return 0;
}