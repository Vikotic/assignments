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