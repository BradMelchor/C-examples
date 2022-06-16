//Brad Melchor
//COP2535.001
//This program is designed to take input from file and put them into two arrays. If they match it supposed to display that they match and if they dont it should output that they don't match.

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include <list>
using namespace std;

class compareArrays {

private:

	vector<int> Array1Values;

	vector<int> Array2Values;

	int Size;

	vector<int> values;

	vector <int> valueMultiplicity;

	vector<int> values2;

	vector <int> valueMultiplicity2;

	
	int compareArray() {
		//compares the values in the arrays and see if they match, if they don't they aren't the same

		
		if (values == values2 && valueMultiplicity == valueMultiplicity2) {
		
			cout << "The Arrays are the same!!!!" << endl;

			cout << endl;
		}
		
		else {
			cout << "The Arrays aren't the same..." << endl;

			cout << endl;

		}

		
		return 0;
	}


	void compareSize() {

		//Compares the length of both of the vectors. if they aren't the same length they output saying so.
		if (Array1Values.size() != Array2Values.size()) {

			cout << " The Arrays have differing sizes. " << endl;

			cout << endl;

		}

		else {

			cout << "The Arrays have the same size." << endl;

			cout << endl;
		}
	};

	void multiplicity1(){
		
		//search algorithm used to take a value in the vector and then push it into two different vectors
		
		//initializes count, a variable to compare index numbers to be searches and initializes vectors.
		int count = 1;

		int searchNumber = 1;


		//sets first element to first value in Array1Values vector.
		int element = Array1Values[0];

		//while loop runs until the last value of Array1Values
		while (searchNumber < Array1Values.size()) {

			//compares next number with the value, if same number it increments count and the index. 
			if (Array1Values[searchNumber - 1] == Array1Values[searchNumber]) {

				count++;

				searchNumber++;
				
			}

			else {
			
				// if the value isn't a repeat, it pushes the number to values vector and the count to multiplicty vector
				values.push_back(element);

				valueMultiplicity.push_back(count);

				//assigns the index to element then increments to the next number to be searched.
				element = Array1Values[searchNumber];
				searchNumber++;

				//resets count to 1;
				count = 1;
			}
		
		}

		//pushes the last elements value and multiplicity to the different vectors.
		values.push_back(element);

		valueMultiplicity.push_back(count);

		
	
	}

	void outputMultiplicity() {
	
		//outputs the Array with its values and multiplicity
		cout << "Array 1 has the following values and multiplicity:" << endl;

		cout << endl;

		//for loop steps through each x index for both vectors.
		for (int x = 0; x < values.size(); x++) {

			cout << values[x] << " has a multiplicity of " << valueMultiplicity[x] << endl;

		}

		cout << endl;
	
	}
	void multiplicity2() {

		//search algorithm used to take a value in the vector and then push it into two different vectors

		//initializes count, a variable to compare index numbers to be searches and initializes vectors.
		int count = 1;

		int searchNumber = 1;


		//sets first element to first value in Array2Values vector.
		int element2 = Array2Values[0];

		//while loop runs until the last value of Array2Values
		while (searchNumber < Array2Values.size()) {

			//compares next number with the value, if same number it increments count and the index. 
			if (Array2Values[searchNumber - 1] == Array2Values[searchNumber]) {

				count++;

				searchNumber++;

			}
			else {
				// if the value isn't a repeat, it pushes the number to values vector and the count to multiplicty vector
				values2.push_back(element2);

				valueMultiplicity2.push_back(count);

				//assigns the index to element then increments to the next number to be searched.
				element2 = Array2Values[searchNumber];
				searchNumber++;

				//resets count to 1;
				count = 1;
			}

		}

		//pushes the last elements value and multiplicity to the different vectors.
		values2.push_back(element2);

		valueMultiplicity2.push_back(count);

		

	}
	void outputMultiplicity2() {


		//outputs the Array with its values and multiplicity
		cout << "Array 2 has the following values and multiplicity:" << endl;

		cout << endl;

		//for loop steps through each x index for both vectors.
		for (int x = 0; x < values2.size(); x++) {

			cout << values2[x] << " has a multiplicity of " << valueMultiplicity2[x] << endl;

		}
		cout << endl;


	}
	
	void vectPush(int array[], int Size) {
		
		//initializes a pointer variable
		int* intPtr = array;


		//sets max elements to be max value then subtracts as element is placed in proper position
		for (int maxElement = Size - 1; maxElement > 0; maxElement--) {

			//checks to see if value being sorted is greater than the next if it is it calls swap function
			for (int index = 0; index < maxElement; index++) {

				if (intPtr[index] > intPtr[index + 1])
					swap(intPtr[index], intPtr[index + 1]);
			}
		}

		//takes values and pushes them into a vector to be compared
		for (int x = 0; x < Size; x++) {

			Array1Values.push_back(intPtr[x]);

		};

		popZero1();

	}
	void vectPush2(int array[], int Size) {

		//creates pointer variable for second array
		int* intPtr2 = array;

		//sets max elements to be max value then subtracts as element is placed in proper position
		for (int maxElement = Size - 1; maxElement > 0; maxElement--) {

			//checks to see if value being sorted is greater than the next if it is it calls swap function
			for (int index = 0; index < maxElement; index++) {

				if (intPtr2[index] > intPtr2[index + 1])
					swap(intPtr2[index], intPtr2[index + 1]);
			}
		}

		//pushes values into a vector to be compared
		for (int z = 0; z < Size; z++) {

			Array2Values.push_back(intPtr2[z]);
		};

		popZero2();

	}

	void swap(int& a, int& b) {
		int temp = a;
		a = b;
		b = temp;
	}

	void popZero1() {

		int value = 0;
		bool found = false;

		for (int x = 0; x < Array1Values.size(); x++) {
			for (int x = 0; x < Array1Values.size(); x++) {
				if (value == Array1Values[x]) {

					Array1Values.erase(Array1Values.begin());

				}
			}
		}

	}
	void popZero2() {

		int value = 0;
		bool found = false;

		for (int x = 0; x < Array2Values.size(); x++) {
			for (int x = 0; x < Array2Values.size(); x++) {
				if (value == Array2Values[x]) {

					Array2Values.erase(Array2Values.begin());

				}
			}
		}

	}
public:

	void setvalues() {
		//public array for the class to access private member functions

		//sets size of the arrays and initialized two arrays with inputs from different files
		const int size = 10;

		Size = size;

		static int Array1[size];

		static int Array2[size];

		//initializes file for first array to get data from
			ifstream inputFile;
			inputFile.open("ComFile1.txt");

			if (!inputFile) {

				cout << "Error opening data file\n";

			}

			else
			{
				for (int x = 0; (x < Size) && (inputFile >> Array1[x]); x++);

			};

			//closes file 
			inputFile.close();

			//opens second file to get data from
			ifstream inputFile2;
			inputFile2.open("ComFile2.txt");

			if (!inputFile2)

				cout << "Error opening data file\n";

			else
			{

				for (int x = 0; (x < Size) && (inputFile2 >> Array2[x]); x++);

			};

			//closes second file
			inputFile2.close();


			//calls all the different private functions to perform their functions
			//pushes values into different array 
			vectPush(Array1, Size);
			vectPush2(Array2, Size);

			
			//takes both arrays put them into vectors then displays their values and their multiplicity
			multiplicity1();
			multiplicity2();

			//compars vector values and sizes
			compareArray();
			compareSize();
		
			outputMultiplicity();
			outputMultiplicity2();
	}
};
int main()
{
	//makes instance of compareArrays class and names it compare.
	compareArrays compare;

	//calls setvalues public method from compare class.
	compare.setvalues();

	cout << endl;
	cout << endl;
	cout << endl;
	//terminates program
	return 0;
}