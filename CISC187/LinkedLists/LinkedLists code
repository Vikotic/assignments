The linked list activity code's goal is to add and remove nodes from the front of the list. To do this, I used
what we learned about linked lists in the text provided and what we learned from before about pushing and popping.
Most of the explanation will be in the video for how the code works. We decided to do a loop that takes in the 
amount of nodes that the user would like to create and the amount of nodes that the user would like to delete. This
activity was interesting and a bit more challenging than the rest because of having to keep track of the different fields
of each node which are the data field and the next field which has an address of the next node. I hadn't worked with
these types of lists before so it was a fun challenge to research it and figure out their strengths and weaknesses.
Speaking of which, the strengths of this type of list is the easy ability to create and delete nodes since it does
not take a linear O(N) time to create or delete nodes and only takes O(1) time for each action or step. However, its
weakness is searching as it does have to go through each node and look at the next address to find the value wanted.

```cpp
#include <iostream>
using namespace std;

class LinkedList {
private:
	struct Node {
		int data;
		Node* next; // pointer to next node
	};

	Node* head; // pointer to head node

public:
	// constructor so that head is initialized
	LinkedList() : head(nullptr) {}

	// add a new node at the front of the list
	void pushFront(int value) {
		Node* newNode = new Node;
		newNode->data = value; // assign value to data field
		newNode->next = head; // assign head to next field
		head = newNode; // updates head so newNode is the first node
	}

	// remove the node at the front of the list
	void popFront() {
		if (!head) {
			cout << "List is empty. Nothing to remove." << endl;
			return;
		}
		Node* temp = head;
		head = head->next;
		delete temp;
	}

	void printList() const {
		if (!head) {
			cout << "List is empty." << endl;
			return;
		}
		Node* current = head;
		while (current) { // checks if there is a current that isn't null
			cout << current->data; // prints data field of current
			if (current->next) { // checks if the current node has a next node
				cout << " -> ";  // print arrow only if there's a next node
			}
			current = current->next;
		}
		cout << endl;  // end the line
	}
};

int main() {
	LinkedList list;
	int n;
	int value;
	int toDelete;

	cout << "How many nodes do you want to create? ";
	cin >> n;

	// create n nodes
	for (int i = 0; i < n; i++) {
		cout << "Enter value for node " << (n - i) << ": ";
		cin >> value;
		list.pushFront(value);
	}

	cout << "\nThe linked list after creating " << n << " node(s) is:" << endl;
	list.printList();

	cout << "\nHow many nodes do you want to delete from the front? ";
	cin >> toDelete;

	// delete nodes from the front
	for (int i = 0; i < toDelete; i++) {
		list.popFront();
	}

	cout << "\nThe linked list after attempting to delete "
	     << toDelete << " node(s) is:" << endl;
	list.printList();

	return 0;
}
```
