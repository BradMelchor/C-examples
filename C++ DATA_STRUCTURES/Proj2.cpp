//Brad Melchor
//COP2535.001
//This project should take input from a file and put into two arrays then sort it using different sort algorithms.

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

class sortIt {

private:
	//sets Size as a private variable to be called by public function
	int Size;

	void getdata() {
		//takes inputfile and assigns values to an array
		ifstream inputFile;
		inputFile.open("random.txt");
		
		//sets SIZE to 200
		const int SIZE = 200;
		Size = SIZE;

		//makes static array for bubble sort
		static int BubbleArray[SIZE] = {};

		//makes static array for selection sort
		static int SelectionSortArray[SIZE] = {};

		//public variable used for searches
		int value = 869;

		//checks if input file is there, if not gives error message.
		if (!inputFile)
			cout << "Error opening data file\n";
		else {

			//steps through bubblearray and assigns each value the next value in the file.
			for (int count = 0; count < SIZE; count++)
				inputFile >> BubbleArray[count];
		};

		//populates 2nd array with values from first array.
		for (int i = 0; i < SIZE; i++) {

			SelectionSortArray[i] = BubbleArray[i];

		};

		//closes file
		inputFile.close();
		
		//calls private methods for each sort and search algorithms.
		bubbleSort(BubbleArray, Size);
		selectionSort(SelectionSortArray, Size);
		linearSearch(BubbleArray, Size, value);
		binarySearch(BubbleArray, Size, value);

	};

	void bubbleSort(int array[], int Size) {

		//count is used to display number of exchanges
		int count = 0;

		//sets max elements to be max value then subtracts as element is placed in proper position
		for (int maxElement = Size - 1; maxElement > 0; maxElement--) {
		
			//checks to see if value being sorted is greater than the next if it is it calls swap function
			for (int index = 0; index < maxElement; index++) {

				if (array[index] > array[index + 1])
					swap(array[index], array[index + 1]);
				
				//increments could
				count++;
			}
			
		}

		//displays number of exchanges.
		cout << "The Bubble Sort exchanged " << count << " values.\n\n";
	};

	void selectionSort(int array[], int Size) {

		//selectionSort creates min values and where to start. count2 displays how many exchanges occur.
		int minIndex, minValue;
		int count2 = 0;

		for (int start = 0; start < (Size - 1); start++) {

			//starts at position one and sets minvalue and the index to the first element in the array aka array[0].
			minIndex = start;

			minValue = array[start];

			//steps through each of the elements and compares them. if the value is less than the position it sets the min value to the index in the array. 
			for (int index = start + 1; index < Size; index++) {

				if (array[index] < minValue) {
					minValue = array[index];
					minIndex = index;

				};
				//increments the count to display
				count2++;
			};
			//calls swap function to swap the positions.
			swap(array[minIndex], array[start]);

		};

		//displays count2.
		cout << "The Selection Sort exchanged " << count2 << " values.\n\n";


	};

	//takes in the array, the size, and the value we are looking for then search the array for the index.
	int linearSearch(int array[], int Size, int value) {

		//count to display number of positions searched.
		int count3 = 0;

		//sets variables to make a start index, the position of where to start and a bool to see if the value was found.
		int index = 0;
		int position = -1;
		bool found = false; 

		//makes a while loop that checks if the entire array has been searched, if it finds the value it sets bool to true and exits. if not it goes to the next position and updates count.
		while (index < Size && !found) {

			if (array[index] == value) {
				found = true;
				position = index;

			};
			index++;

			//count to display number of positions that been searched.
			count3++;
		};
		
		//outputs count3.
		cout << "The number of linear search comparisons made were " << count3 << ". \n\n";

		//returns the position in which the number was found. if not found returns a -1.
		return position;
	};

	//binary search that takes in array, the size ofthe array and the value to be searched. 
	int binarySearch(int array[], int Size, int value){

		//count4 updates when a number has been searched.
		int count4 = 0;

		//initializes variables for a first number, middle, and the last number to be searched then sets position to -1. bool variable if the number was found or not.
		int first = 0;
		int last = Size - 1;
		int middle;
		int position = -1;
		bool found = false;

		//sets while loop that checks if the number has been found and that the entire array hasn't been searched.
		while (!found && first <= last) {

			//middle variable is size of the array divided by two. Size is adding the first and last numbers together.
			middle = (first + last) / 2;

			//updates count each time it searches a number
			count4++;

			//if the middle position is the value to searched, then returns the middle position if it matches.
			if (array[middle] == value) {
				found = true;
				position = middle;
			}

			//checks to see if the middle value is more than the value to be searched, if it is then the number is in first part of the array.
			else if (array[middle] > value) {
				last = middle - 1;
			}

			else
				//if not first part of the array then it searched the 2nd half of the array.
				first = middle + 1;
		}

		//displays count4 as how many times it searched numbers.
		cout << "The Binary Search compared " << count4 << " numbers.\n\n";

		//returns the position if found otherwise returns -1 as not found.
		return position;


	};

	//swap private method that sets a value into a temp variable then "swaps" the values positions of two variables.
	void swap(int& a, int& b) {
		int temp = a;
		a = b;
		b = temp;
	};

public:

	//public method that sets the data.
	void setData() {
		getdata();
	};
};

int main()
{
	//calls an instance of the sortit class called sort
	sortIt sort;

	//calls the public setData method of the sort class. 
	sort.setData();

	//returns 0 to end program.
		return 0;

	};
