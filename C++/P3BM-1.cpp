//Bradley Melchor
//cop2000.CM1
//This program will find what substance boils or freezes from temperature input by user.

#include <iostream>
#include <cctype>
using namespace std;

int main()
{
	double degree; //degree input
	const double max_degree1 = 676,// max and min values to help with is/else
		max_degree2 = 172,
		max_degree3 = 212,
		max_degree4 = -306,
		min_degree1 = -173,
		min_degree2 = -38,
		min_degree3 = -362,
		min_degree4 = 32;

	cout << "Please enter a number to find the freezing point\n and boiling point of an substance.\n";
	cin >> degree; //asks for degrees from user
	while (cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << "an invalid answer was submitted, " //designed for an invalid answer, will ask to rerun the program
			<< " enter a valid number.\n";
		cin >> degree;


	}
	if (degree >= max_degree1)
		cout << "Water, Oxygen, Mercury, and Ethyl alcohol will boil at that temperature"; //temperature input in degrees will give information on substances boil and freeze points
	else if (degree <= max_degree3 && degree >= max_degree2)
		cout << "Water and Oxygen will boil at that temperature.";
	else if (degree <= max_degree2 && degree >= min_degree4)
		cout << "Ethyl alcohol and Oxygen will boil at that temperature.";
	else if (degree <= 32 && degree > min_degree2 )
		cout << "Water will freeze and Oxygen will boil at that temperature.";
	else if (degree <= min_degree2 && degree > min_degree1)
		cout << "Mercury, and water will freeze, Oxygen will boil at that temperature.";
	else if (degree <= min_degree1 && degree > min_degree3)
		cout << "Ethyl alcohol, Mercury and water will freeze, Oxygen will boil at that temperature.";
	else if (degree <= min_degree3)
		cout << "Ethyl alcohol, Mercury, Water, and Oxygen will freeze at that temperature.";
	cin.get();

	return 0;
}