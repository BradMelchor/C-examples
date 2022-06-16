//Brad Melchor
//COP2535.001
//This program will take inout from a file make it into a node and put it on a binary tree. Then the tree will be searched for the node by the studentID. 


#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
class TreeNode { //Treenode class

	struct TNode{ //structure of a tree nodecalled TNode
	int id;
	string studentName; //has an id number, students name, the major, and a left and right pointer node.
	string studentMajor;
	TNode*left;
	TNode* right;

	TNode(int id1, string stuName, string stuMajor, TNode* left1 = nullptr, TNode* right1 = nullptr) {
		id = id1;
		studentName = stuName;
		studentMajor = stuMajor; //constructor that can be used to create a node. 
		left = left1;
		right = right1;
	}
	};

private:

	TNode *root; //root of the tree

	void insertNode(TNode *&root, int id, string name, string major) { //inserts node on the tree
		//if empty makes new root
		if (!root) {
		
			root = new TNode(id, name, major);
		}
		//if node is id return.
		if (root->id == id)
			return;
		//if doesn't exist place on the tree.
		if (id < root->id)
			insertNode(root->left, id, name, major);
		else
			insertNode(root->right, id, name, major);
	
	};
	
	void showInOrder(void) { // displays in order
		displayInOrder(root);
	};

	void displayInOrder(TNode* root) { //show left side of tree, the value then right side of tree.
		if (root) {
			displayInOrder(root->left);
			cout << root->id << '\t' << root->studentName << '\t'<< root->studentMajor<< endl;
			displayInOrder(root->right);
		
		}
	
	}
	void display() { //displays information of students in tree then asks user to insert input. 
		bool flag;
		string userChoice;
		int num2Search;
		cout << "Student ID" << '\t' << "Student Name" << '\t' << '\t' << "Student Major" << endl; //displays header

		showInOrder(); //displays all students in tree 
		cout << endl << "End of tree" << endl << endl;

		
			cout << "Enter a student ID (press Q to quit):";//gets user input
			getline(cin, userChoice);
			if (userChoice == "q" || userChoice == "Q") { //if q or Q, quit the program
				cout << "End of program" << endl;
				return;
			}
		while (userChoice != "q" && userChoice != "Q") { //while loop to loop through.

				num2Search = stol(userChoice); //converts string into an integer 
				if ((userChoice.length() < 7) || (userChoice.length() > 8) || (num2Search < 0)) { //out of bounds OR negative value. 

					cout << "invalid input, try again: ";
					getline(cin, userChoice);

				}
				else{

					flag = SearchTree(num2Search); //searches tree for student id returns true if exists.
						if (flag == true) { //if found on tree, displays information.
							search(num2Search);
							
							
						}
						else { //not found, tell em.

							cout << "Student " << num2Search << " is not found!" << endl << endl;

							
						}
						
				}

				cout << "Enter a student ID (press Q to quit):"; // reask for input.
				getline(cin, userChoice);
			}


	}
	void search(int num)const { //searches tree for id, displays information
		TNode* tree = root;
		while (tree)
		{
			if (tree->id == num) {

				cout << "Student ID:" << '\t' << tree->id << endl;
				cout << "Student Name:" << '\t' << tree->studentName << endl;
				cout << "Student Major:" << '\t' << tree->studentMajor << endl << endl;
				return;
				

			}
			else if (num < tree->id) {
				tree = tree->left;
				

			}
				
			else if ( num > tree->id){
				tree = tree->right;
				
			}
			else {
				cout << "Student " << num << "is not found!" << endl;
			}
				
				

		}
		return;
	
	}
	
	bool SearchTree(int num) const { //searches tree for id, if found return true. else, returns false.
	TNode* tree = root;
	while (tree) {
	
		if (tree->id == num)
			return true;
		else if (num < tree->id)
			tree = tree->left;
		else
			tree = tree->right;

	
	}
	return false;
	}




public:
	TNode BinaryTree() { //constructor
		root = nullptr;
		setdata();
		
	}

	void setdata() { // public method that sets data
		root = nullptr;
		ifstream inputFile;
		inputFile.open("students.txt"); //takes input 

		int id;
		string gline;
		string Fname;
		string Lname;
		string name;
		string major;
		string major1;
		string major2;

		cout << "Populating Binary Tree Structure" << endl << endl;
		cout << "Reading contents....." << endl << endl; //header for populating tree 

		if (!inputFile) {
			cout << "Error opening data file\n"; //no file.
		}
		else {

			while (inputFile) {
				getline(inputFile, gline); //takes input and puts into variables.

				inputFile >> id >> Fname >> Lname >> major1 >> major2;


				name = Fname + " " + Lname; //combines information about name and merges it into a full name.
				major = major1 + " " + major2; //combines info on major and combines it into student major.

				insertNode(root, id, name, major); //takes variables and creates nodes.

				if (inputFile.eof()) break; //break if end of file is found.
			}



		}
		inputFile.close(); //close input to prevent dataleak. 
		display(); //displays information.

	}
	
};
int main() //main method
{
	
	TreeNode Node; //creates instance of TreeNode called Node.

	
	Node.setdata(); //uses public method to set information.

	return 0; //returns 0;

}