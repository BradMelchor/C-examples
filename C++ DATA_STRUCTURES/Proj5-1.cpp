//Brad Melchor
//COP2535.001
//This project is supposed to take strings from a file, tell if they are properly delimited and push/pop them onto a stack.

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <memory>

using namespace std;

class StrStack { //class strStack
	
private:
	
unique_ptr<char []>StackArray; //unique pointer to stack
int capacity; //how big it can be
int top; //the top of the stack
int counter = 1; // used to print lines

void readValues() { //takes input puts it into a str variable called sentence.

		string sentence;

		bool flag= false;
		bool endFlag = false;
		
	ifstream inputFile;

	inputFile.open("string.txt"); // the document

	if (!inputFile)
		cout << "Error opening data file\n"; //no file.
	else {

		cout << "Processing input file...." << endl << endl; // display beginning
		cout << "String:" << endl;

		while (inputFile) { //if file is found, get input from file

			getline(inputFile, sentence);

			checkSentence(sentence); //calls checkSentence

			if (inputFile.eof()) {
				cout << endl << "End of File" << endl;
				break; //reaches end of file and breaks the loop.
			} 
		}
	}


	inputFile.close(); //close file

	};

	void push(char x) { //checks that the stack isn't full then pushes char value to the stack
		if (top == capacity)
			throw Overflow();
		StackArray[top] = x;
		top++; //increments value of top
	};

	void pop() {
		if(isEmpty())
			throw Underflow(); //if empty, can't subtract

		top--;//reduces top value
		
	};
	
	bool isEmpty() {
		return (top == 0); //checks to see if stack is empty.
		
	};

	char peektop() {
	
		char val; //checks what char value is top then returns it.

		val = StackArray[top];
		return val;
	}
	bool isFull() {
		bool answer = false; //if the stack is full return true. 

		if (top == capacity) {
			answer = true;
		}

		return answer;
	
	}
	void checkSentence(string val) { //takes in string.
		
		for (int x = 0; x < val.length(); x++)
		{

			// Checks if there is delimiters
			if (val[x] == '(' || val[x] == '[' || val[x] == '{')
			{
				push(val[x]); //pushes the character to stack
			}
			else if (val[x] == ')' || val[x] == ']' || val[x] == '}') //finds closing bracket and see if there is one in stack
			{
				
				if ( isEmpty())
				{
					
					return;
				}

				if (val[x] == ')' && peektop() == '(') //finds closing delimiter, checks the top to see if there is a matching (
				{
					pop(); //if found removes from stack
				}
				else if (val[x] == ']' && peektop() == '[') //finds closing delimiter, checks the top to see if there is a matching [
				{
					pop();//if found removes from stack
				}
				else if (val[x] == '}' && peektop() == '{') //finds closing delimiter, checks the top to see if there is a matching {
				{
					pop();//if found removes from stack
				}
				else
				{
					//ignores if it doesn't match
				}
			}
			if (isEmpty()) //if stack is empty after full string then it is delimited.
			{
				cout << counter << ". is properly delimited" << endl;
				counter++;

			}
			else
			{
				if((val[x] == '(' || val[x] == '[' || val[x] == '{') && !isEmpty()) //if the stack is empty but there is an opening bracket left over
				cout << counter << ". is not properly delimited" << endl;
				counter++;
				break; //breaks the loop
		}
		
			
		}
		
	}
	
	
	class Overflow {};
	class Underflow {};
	
	
	
public:

	StrStack(int capacity, int top) { //constructor for strStack
		StackArray = make_unique<char[]>(capacity);
		this->capacity = capacity;
		this->top = top;
	};
	void setData() { //public method to call private method

		readValues();
	}
	
};
int main()
{
	//program code goes here

	StrStack str(1000, 0); //sets strStack capacity to 1000, sets top to 0

	str.setData(); //calls public method.

	return 0;

} 