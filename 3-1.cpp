#include <iostream>
#include <string>
using namespace std;

struct node {
	int data;
	node* nextNode;
};


class LinkedList {
private:
	node* head;
	node* tail;
public:
	LinkedList() {

		head = NULL;
		tail = NULL;
	}

	void addFront(int n);
	int removeFront();
	int empty();
	int front();
};

void LinkedList::addFront(int n) {
	node* temp = new node;

	temp->data = n;

	if (head == NULL) {
		head = temp;
		tail = temp;
	}
	
	else {
		temp->nextNode = head;
		head = temp;
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
		return 1;
	}
	else {
		return 0;
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
			test.addFront(number);
		} 
		else if (command[0] == 'r') {
			cout << test.removeFront() << '\n';
		}
		else if (command[0] == 'f') {
			cout << test.front() << '\n';
		}
		else {
			cout <<  test.empty() << '\n';
		}

	}

}

