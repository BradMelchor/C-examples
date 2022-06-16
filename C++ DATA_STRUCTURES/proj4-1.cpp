//Brad Melchor
//COP2535.001
//This program is designed to take input from file and user then do a series of commands like popping a node off a linked list/ deleting the beginning node, inserting one to the beginning/end. then exit if a user doesnt want to continue. 

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;
class linkDaList {

	struct ListNode { //listnode structure
		string val;
		ListNode* next;
		ListNode(string value1, ListNode* next1= nullptr) { //constructor for listNodes

			val = value1;
			next = next1;
		}

	};
	
private: //private area of class

	int action;
	string addNames; //names to add to list
	ListNode* head; // linked list

	void add2End(string addNames) { // action 1

		if (head == nullptr) {
			head = new ListNode(addNames); //if nothing add new node.
		}
		else {
			ListNode* nodePtr= head;
			while (nodePtr->next != nullptr) { // traverse to end, when it hits nullptr
				nodePtr = nodePtr->next;
			}

			nodePtr->next = new ListNode(addNames); //adds new node
		}

	}
	void add2Begin(string addNames) { // action 2
		
		ListNode* nodePtr = head; //pass head to nodePtr;
		ListNode* PrevPtr; //make ptr to hold previous listnode.

		if (head == nullptr) {
			head = new ListNode(addNames); //if empty add to head
		}
		else {
			PrevPtr = head;
			nodePtr = head->next; //pushes head to the next node and make new head then connects them
			head = new ListNode(addNames);
			head->next = PrevPtr;
		}

	}

	void deleteName(string name) { //finds a name in linkedlist and deletes the node.

		ListNode* nodePtr = head; 
		ListNode* previousPtr = nodePtr;
	
		if (!head|| head == nullptr) //if no head or head is a null, say list empty.
			cout << "List is empty" << endl<< endl;

		if (head->val == name) { // if head value is name to be deleted, sets a delete node to head value and assign head to the node after.
			nodePtr = head;
			head= head->next;
			delete nodePtr;
		}
		else {
			nodePtr = head;
			while (nodePtr != nullptr && nodePtr->val != name) { //traverses linked list until it finds name.
				previousPtr = nodePtr;
				nodePtr = nodePtr->next;
			}

			if (nodePtr) { //if name is found links previous node to the node after the one to be deleted then deletes node.
				previousPtr->next = nodePtr->next;
				delete nodePtr;
				cout << endl << endl << "Student deleted. " << endl << endl;
			}
			else { //name was not found in list.
				cout << endl<< "Student does not exist on the wait list." << endl << endl;

			}

		
		}
		
	}
	
	void deleteBegin() { // action 3

		ListNode* nodePtr=head;
		if (!head || head == nullptr) {
			//do nothing if head is null or missing
		}
		else {

			if(nodePtr->next != nullptr || nodePtr != nullptr || head->next != nullptr) //checks to see if list isnt single item in list,
				//the node isn't null or the next pointer isn't null.
			{
				nodePtr = head; //assigns head to deletable node, then sets head to the node after and deletes delete node.
				head = head->next;
				delete nodePtr;
			}
			else{ //failsafe to catch anything I forgot to search for.
				delete nodePtr;
				}

		
		}

		
	}
	void deleteEnd() { // action 4

		ListNode* nodePtr = head;
		ListNode* previousPtr=nodePtr;

		if (!head) {
			cout << "empty list"<< endl; //checks if list null/empty.

		}

		else{

			while (nodePtr->next!= nullptr) //while the next pointer isnt null, transverse list. when it reaches the lode before last stops.
			{
				previousPtr = nodePtr;
				nodePtr = nodePtr->next;
				
			}
			if (nodePtr) { //last node in the list

				//delete the last node
				previousPtr->next = nullptr; //sets pointer of node before last to null.
				delete nodePtr;
			}
		}
	}

	void displayList() { // displays the list
	
		ListNode *nodePtr = head; //pulls in linked list

		cout << "The Wait List: " << endl << endl;

		int count = 1; //counter for names in list.

		if (nodePtr == nullptr) {
			cout << "List Empty" << endl; // if list null, display empty list.
		}
		else {
			while (nodePtr && nodePtr!= nullptr) { //checks to see node value and not go out of bounds
					cout << count << ". " << nodePtr->val << endl; //displays value of listnode
					nodePtr = nodePtr->next; //transverses to next listnode
					count++; //adds count for next name
			}
		}
		cout <<endl<< "End of List."<< endl; //if list empty, displays empty list.
	
	
	}

	void deleteWaitList() { // takes in user input to delete students on the waitlist.
		string name2Delete;
		string userChoice;

		cout << endl << endl << "Would you like to delete a student by name (y= yes, n =no):";
		getline(cin, userChoice); //grabs user input using the cin method and assigning it to userChoice.


		while (userChoice != "n" && userChoice != "N" && userChoice != "y" && userChoice != "Y") { //checks for invalid input
			cout << "invalid response, please enter y = yes, n = no:";
			getline(cin, userChoice); //asks for new choice.
		}

		if (userChoice == "n" || userChoice == "N") { //if choice is no, ends program.
			cout << endl << "Program end." << endl;
		}

		while (userChoice != "n" && userChoice != "N" && userChoice == "y" || userChoice == "Y") { 

			//if choice is yes and not no, ask for names to delete
			cout << "Enter the full name of the student to delete:";

			getline(cin, name2Delete); //gets name to delete
			deleteName(name2Delete); //calls delete function search for name.

			displayList(); // displays new wait list.

			cout << endl << endl << "Would you like to delete a student by name (y= yes, n =no):"; //asks for user input again

			getline(cin, userChoice);

			if (userChoice == "n" || userChoice == "N") { //adds if statement to break program from loop 
				cout << endl << "Program end." << endl;
				break; 
			}
		}
	
	}

public:

	~linkDaList() { //deconstructor to get rid of dead linkedlists..
		ListNode* nodePtr = head;
		while (nodePtr != nullptr) {

			ListNode* garbage = nodePtr;
			nodePtr = nodePtr->next;
			delete garbage;
		}
	}

	void setdata() { //takes input from file and fills list with input.
	
		ifstream inputFile;
		inputFile.open("WaitList.txt"); 
		ListNode* begin = nullptr;
		string name;
		string addName;
		string actions;

		if (!inputFile)
			cout << "Error opening data file\n"; //no file.
		else {
			while (inputFile) { //if file is found, get input from file and splices it to get action and names from strings.

				getline(inputFile, name);

				actions = name.substr(0, 1); //gets first lettet of string and assigns to actions.

				if (name.length() > 2) {//makes sure the name string is longer than 2 characters, prevents splicing lines with only numbers/out of bounds.
					addName = name.substr(2, name.length() - 1); //name is from the 3rd position to the end of the line, - 1 to not do carriage return.
				}
				else {
					addName = ""; //doesn't assign names to 1-2 spaced name strings.
				}

				if (actions == "1") { // add to end
					addNames = addName;

					add2End(addNames);
				
				}
				else if (actions == "2") { //add to begin
					addNames = addName;
					add2Begin(addNames);
				}
				else if (actions == "3") { // delete begin
				
					 deleteBegin();
				}

				else if(actions == "4") {//delete end

					 deleteEnd();
				}
				else {
					cout << "wrong Input"; // captures bad input
				}
				if (inputFile.eof()) break; //reaches end of file and breaks the loop.

				
			};
			inputFile.close(); //closes file to prevent data leaks
			
		
		};
		displayList(); // show list
		deleteWaitList(); // get user input and deletes names from waitlist.
	
	}

};
int main() //main program
{
	//program code goes here
	
	linkDaList links; //new reference to linkDaList class.

	links.setdata(); // calls public setdata method.

	return 0; //ends program.

}