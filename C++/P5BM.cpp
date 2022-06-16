//Debbie Reid
//COP2000.C01
//Program description here

#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

//prototypes go here
void getScore( double &num1, double &num2, double &num3, double &num4, double &num5);
void calcAverage(double num1, double num2, double num3, double num4, double num5);
double findLowest(double lowest);
void testFile(ifstream& in);
void openFile(ifstream& in);
void display();
int main()
{
	ifstream input;

	//to do
	double num1 = 0;
	double num2 = 0;
	double num3 = 0;
	double num4 = 0;
	double num5 = 0;
	//variables
	//display the program purpose
	display();
	//open the input file
	openFile(input);

	//    calling getScores 5 times
    getScore( num1, num2, num3, num4, num5);
	//call calcAverage()
	void CalcAverage(double &num1, double &num2, double &num3, double &num4, double &num5);
	//close the input file
	input.close();

	return 0;
}
void openFile(ifstream &input)//   test the file opened properly
	//get the input scores from the file
{
	input.open("grades.txt");
	testFile(input);

}
void testFile(ifstream& input)
{
	if (!input)
	{
		cout << "The input file did not open properly" << endl;
		exit(8901);
	}
}
void getScores(double &num1, double &num2, double &num3, double &num4, double &num5)
{

	ifstream input;
	input >> num1;
	input >> num2;
	input >> num3;
	input >> num4;
	input >> num5;
	
}
void calcAverage(double num1, double num2, double num3, double num4, double num5)
{
	double lowest = 0;
	double avg = 0.0f;
	//     within calcAverage, call findLowest
	findLowest(lowest); 
	avg = ((( num1, num2, num3, num4, num5) - lowest) / 4.0);
	cout << "the average Test score is " << avg << endl;
}
int findLowest(double num1, double num2, double num3, double num4, double num5)
{
	double lowest = num1;
		if (num1 > num2)
			num2 = lowest;
		if (num2 > num3)
			num3 = lowest;
		if (num3 > num4)
			num4 = lowest;
		if (num4 > num5)
			num5 = lowest;
		cout << "The lowest score dropped is " << lowest << endl;
		return lowest;
}
void display()
{
	cout << "The purpose of the program is to find the average score "
		<< "and drop the lowest score from an input file" << endl;
}