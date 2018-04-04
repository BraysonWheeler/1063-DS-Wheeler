///////////////////////////////////////////////////////////////
// Title:            List priority Queue
// Files:            priority_queue.cpp, input_data.txt, priority_out.txt
// Semester:         (1063 data structures ) Spring 2018
//
// Author:           (Logan Wheeler)
// Email:            (lbw98@att.net)
// Description:
//       The program takes in commands from an imput file then arranges
//        them into a priority queue. The input is full of names specifically
//        animal names then arranges them from shortest to longest.
//        in the input file is commands named push and pop that do exactly what
//        they say. When the command push is called it will push an item into the Queue
//        then prioritizes it based on length. When the command pop is called
//        the first in will be taken out. Once the end of file is reached whats left
//        is outfiled to priorist_out.txt
//////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


struct Node
{
	string val;
	Node *next;
	Node()
	{
		val = " ";
		next = NULL;
	}
	Node(string v)
	{
		val = v;
		next = NULL;
	}
};

/**
* class Queue
*      Inserts words into a queue then arranges
*       them based on priority.
* Methods:
*  - Queue()       : constructor
*  - string pop()  : pops item off queue returns item
*  - void push()   : Pushs item onto queue
*  - void priority() : prioritizes queue based on length
*  - bool empty()   : Checks to see if queue is empty
*  - bool pop()     : takes an item out fo the queue. place an item into
*                       a value that is passed by reference
*/

class Queue
{
private:
	Node * Front;
	Node *Rear;

public:
	/**
	* Queue
	* constructor
	*
	* params:
	*     - none
	*/

	Queue()
	{
		Front = Rear = NULL;
	}

	/**
	* function pop: takes item out Queue, returns item popped
	*
	* parameters: ofstream outfile
	*
	* returns string
	*/
	string pop(ofstream &outfile)
	{
		if (!empty())
		{
			Node *temp = Front;   // temp pointer so we can delete node
			string v = temp->val; // grab value out of node
			Front = Front->next;  // move pointer to next node
			delete temp;          // give mem back to system
			return v;
		}
		else
		{
			outfile << "error: cannot pop off empty queue.";
			return " ";
		}
	}

	/**
	* function push: pushes an item onto a queue
	*
	* parameters: string V
	*
	* returns : nothing
	*/
	void push(string v)
	{
		Node *n = new Node(v);

		// handle the empty case
		if (empty())
		{
			Front = n;
			Rear = n;
		}
		else
		{
			// not empty add to rear
			Rear->next = n;
			Rear = n;
			Priority();
		}
	}

	/**
	* function Priority: prioritizes(sorts) the queue based
	*                     on word length
	*
	* parameters: none
	*
	* returns : nothing
	*
	*/
	void Priority(){
		Node* t1 = Front;
		Node* t2 = Front;

		string temp = "";

		bool swapped = false;

		while (t1){
			swapped = false;
			t2 = t1->next;
			while (t2){
				if (t1->val.length() > t2->val.length()){
					swapped = true;
					temp = t1->val;
					t1->val = t2->val;
					t2->val = temp;
				}
				t2 = t2->next;
			}
			t1 = t1->next;
		}
		if (!swapped){
			return;
		}
	}

	/**
	* function empty: Checks to see if the front is equal to NULL
	*
	* parameters: none
	*
	* returns : nothing
	*
	*/
	bool empty(){
		return (Front == NULL);
	}


	/**
	* function printQueue: prints out queue to file
	*
	* parameters: none
	*
	* returns : nothing
	*
	*/
	string printQueue(ofstream &outfile)
	{
		Node *temp = Front;
		while (temp)
		{
			outfile << temp->val << endl;
			temp = temp->next;
		}
		return " ";
	}

	/**
	* function pop: Removes item from queue. places it into a
	*               string passed by reference
	*
	* parameters: none
	*
	* returns : bool true or false
	*
	*/
	bool pop(string &v)
	{
		if (!empty())
		{
			Node *temp = Front;   // temp pointer so we can delete node
			string t = temp->val; // grab value out of node
			Front = Front->next;  // move pointer to next node
			delete temp;          // give mem back to system
			v = t;
			return true;
		}
		else
		{
			cout << "error: cannot pop off empty queue." << endl;
			return false;
		}
	}
};

int main()
{
	// Declaring output and input file
	ifstream infile;
	infile.open("input_data.txt");
	ofstream outfile;
	outfile.open("priority_output.txt");

	// Declaring Variables
	Queue Q;
	string animal;
	string command;
	string item;

	outfile << "Animals Popped off the Queue: " << endl;

	// Pushs and pops items into queue then sends them to output file
	while (!infile.eof()) {
		infile >> command;
		if (command == "push") {
			infile >> item;
			Q.push(item);
		}
		else
		{
			outfile << Q.pop(outfile) << endl;

		}
	}

	outfile << endl << "Animals Remaining on the Queue (in order of priority):" << endl;
	outfile << Q.printQueue(outfile);

}
