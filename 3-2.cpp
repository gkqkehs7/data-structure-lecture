#include <iostream>
#include <string>
using namespace std;

struct node {
public:
	int data;
	node* nextNode;
};

class LinkedList {
public:
	node* head;
	node* tail;

	LinkedList() {
		head = NULL;
		tail = NULL;
	}

	void addFront(int n);
	void showList();
	void addBack(int n);
	int removeFront();
	int front();
	int empty();

};

void LinkedList::addFront(int n) {
	node* newNode = new node;

	newNode->data = n;

	if (head == NULL) {
		head = newNode;
		tail = newNode;
	}
	else {
		newNode->nextNode = head;
		head = newNode;
	}
}


int LinkedList::removeFront() {
	node* temp = new node;
	if (head == NULL) {
		return -1;
	}
	else {
		temp = head;
		head = head->nextNode;

		return temp->data;
	}
}




int LinkedList::front() {
	if (head == NULL) {
		return -1;
	}
	else {
		return head->data;
	}
}


int LinkedList::empty() {
	if (head == NULL) {
		return -1;
	}
	else {
		return 0;
	}
}

void LinkedList::showList() {
	node* temp = head;

	if (empty()) {
		cout << -1 << '\n';
	}
	else {
		while (temp != tail) {
			cout << temp->data << " ";
			temp = temp->nextNode;
		}
		cout << temp->data << "\n";
	}
}

void LinkedList::addBack(int n) {
	node* newNode = new node;

	newNode->nextNode = NULL;
	newNode->data = n;


	if (head == NULL) {
		head = newNode;
		tail = newNode;
	}
	else {
		tail->nextNode = newNode;
		tail = newNode;
	}
}



int main() {
	LinkedList test;
	int N;

	cin >> N;

	for (int i = 0; i < N; i++) {
		string command;
		cin >> command;

		if (command[0] == 'a') {
			int number;
			cin >> number;

			if (command[3] == 'F') {
				test.addFront(number);
			}
			else {
				test.addBack(number);
			}
			
		}
		else if (command[0] == 'r') {
			cout << test.removeFront() << '\n';
		}
		else if (command[0] == 'f') {
			cout << test.front() << '\n';
		}
		else if (command[0] == 's') {
			test.showList(test.getHead());
		}
		else {
			cout << test.empty() << '\n';
		}

	}

}

