//Brad Melchor
//COP2535.001
//This project is supposed to take strings from a file, tell if they are properly delimited and push/pop them onto a stack.

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <memory>

using namespace std;

class StrStack {
	
private:
	
unique_ptr<char []>StackArray;
int capacity;
int top;
int counter = 1;

void readValues() {

		string sentence;

		bool flag= false;
		bool endFlag = false;
		
	ifstream inputFile;

	inputFile.open("string.txt");

	if (!inputFile)
		cout << "Error opening data file\n"; //no file.
	else {

		cout << "Processing input file...." << endl << endl;
		cout << "String:" << endl;

		while (inputFile) { //if file is found, get input from file

			getline(inputFile, sentence);

			checkSentence(sentence);

			if (inputFile.eof()) {
				cout << endl << "End of File" << endl;
				break; //reaches end of file and breaks the loop.
			} 
		}
	}


	inputFile.close();

	};
	void push(char x) {
		if (top == capacity)
			throw Overflow();
		StackArray[top] = x;
		top++;
	};

	void pop() {
		cout << top;
		if(isEmpty())
			throw Underflow();

		top--;
		
	};
	
	bool isEmpty() {
		return (top == 0);
		
	};

	char peektop() {
	
		char val;

		val = StackArray[top];
		return val;
	}
	bool isFull() {
		bool answer = false;

		if (top == capacity) {
			answer = true;
		}

		return answer;
	
	}
	void checkSentence(string val) {
		
		for (int x = 0; x < val.length(); x++)
		{

			// Condition to store any opening tags into the stack
			if (val[x] == '(' || val[x] == '[' || val[x] == '{')
			{
				push(val[x]);
			}
			else if (val[x] == ')' || val[x] == ']' || val[x] == '}')
			{
				
				if ( isEmpty())
				{
					
					return;
				}

				if (val[x] == ')' && peektop() == '(')
				{
					pop();
				}
				else if (val[x] == ']' && peektop() == '[')
				{
					pop();
				}
				else if (val[x] == '}' && peektop() == '{')
				{
					pop();
				}
				else
				{
					
				}
			}
			if (isEmpty())
			{
				cout << counter << ". is properly delimited" << endl;
				counter++;

			}
			else
			{
				if((val[x] == '(' || val[x] == '[' || val[x] == '{') && !isEmpty())
				cout << counter << ". is not properly delimited" << endl;
				counter++;
				break;
		}
		
			
		}
		
	}
	
	
	class Overflow {};
	class Underflow {};
	
	
	
public:

	StrStack(int capacity, int top) {
		StackArray = make_unique<char[]>(capacity);
		this->capacity = capacity;
		this->top = top;
	};
	void setData() {

		readValues();
	}
	
};
int main()
{
	//program code goes here
	StrStack str(500, 0);
	str.setData();
	return 0;

} 