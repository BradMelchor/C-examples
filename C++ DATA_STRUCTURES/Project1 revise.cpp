//Brad Melchor
//COP2535.001
//this program is supposed to take data from inside a file and store it into a float array using an object or class. then its supposed to give total rainfall, average rainfall,
//the lowest month and the wettest month. then display it in a nice manner. 

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

class rainfalls {

	private:
		int index;
		int index2;
	void getdata() {

		ifstream inputFile;
		inputFile.open("rain2019.txt");

		const int months = 12;
		float rainfallArray[months] = {};

		if (!inputFile) {
			cout << "Error opening data file\n";
		}
		else {
			for (int count = 0; count < months; count++)
				inputFile >> rainfallArray[count];

		};

		totalRainfall(rainfallArray, months);
		inputFile.close();

	};
	 void totalRainfall(float rainfallArray[], int months) {
		 float sum = 0;
		 for (int r = 0; r < months; r++) {
			 
			 float x = rainfallArray[r];
			 sum += x;
			 

		 };

		 averageRainfall(rainfallArray,sum, months);
		
	};
	void averageRainfall(float rainfallArray[], float sum, int months) {

		float average = (sum / months);
		index = driestMonth(rainfallArray, months);
		index2 = wettestMonth(rainfallArray, months);
		displayReport(rainfallArray, sum, average, index, index2);

	}
	int driestMonth(float rainfallArray[], int months) {
		float lowest = rainfallArray[0];
		int index = 0;
		for (int i = 0; i < months; i++) {
			if (rainfallArray[i] < lowest) {

				lowest = rainfallArray[i];
				index = i;
			};

		};

		return index;
	};
	int wettestMonth(float rainfallArray[], int months) {
		float highest = rainfallArray[0];;
		int index2 = 0;
		for (int i = 0; i < months; i++) {
			if (rainfallArray[i] > highest) {

				highest = rainfallArray[i];
				index2 = i;
			}
		}

		return index2;
	};
	void displayReport(float rainfallArray[],float sum, float average, int index, int index2) {
		string monthName = "";
		string monthName2 = "";
		if (index == 0) {
			monthName = "January";
		}

		else if (index == 1) {
			monthName = "February";
		}

		else if (index == 2) {
			monthName = "March";
		}


		else if (index == 3) {
			monthName = "April";
		}


		else if (index == 4) {
			monthName = "May";
		}

		else if (index == 5) {
			monthName = "June";
		}

		else if (index == 6) {
			monthName = "July";
		}
		else if (index == 7) {
			monthName = "August";
		}

		else if (index == 8) {
			monthName = "September";
		}
		else if (index == 9) {
			monthName = "October";
		}
		else if (index == 10) {
			monthName = "November";
		}

		else if (index == 11) {
			monthName = "December";
		}

		if (index2 == 0) {
			monthName2 = "January";
		}

		else if (index2 == 1) {
			monthName2 = "February";
		}

		else if (index2 == 2) {
			monthName2 = "March";
		}


		else if (index2 == 3) {
			monthName2 = "April";
		}

		else if (index2 == 4) {
			monthName2 = "May";
		}


		else if (index2 == 5) {
			monthName2 = "June";
		}

		else if (index2 == 6) {
			monthName2 = "July";
		}
		else if (index2 == 7) {
			monthName2 = "August";
		}
		else if (index2 == 8) {
			monthName2 = "September";
		}
		else if (index2 == 9) {
			monthName2 = "October";
		}
		else if (index2 == 10) {
			monthName2 = "November";
		}

		else if (index2 == 11) {
			monthName2 = "December";
		}


		cout << "2019 Rain Report for Alachua County\n\n";

		cout << "Total rainfaill:   ";
		cout << setprecision(2) << sum;
		cout << " inches\n";

		cout << "Average monthly rainfall:   ";
		cout << setprecision(2) << average;
		cout << "inches\n";

		cout << "The least amount of rain fell in ";
		cout << monthName;
		cout << " with ";
		cout << rainfallArray[index];
		cout << " inches.\n";

		cout << "The most rain fell in ";
		cout << monthName2;
		cout << " with ";
		cout << rainfallArray[index2];
		cout << " inches.\n\n";

		cout << "End of report\n\n";
	};
public:
	void setvalues() {
		getdata();
	
	}

};
int main()
{
	rainfalls rain;
	rain.setvalues();
	//program code goes here
	return 0;
}

