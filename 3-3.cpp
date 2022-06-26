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

	LinkedList() {
		head = NULL;
	}
	void showList();
	void addBack(int n);
	void remove(int n);
};


void LinkedList::addBack(int n) {

	node* newNode = new node;

	newNode->data = n;

	if (head == NULL) {
		newNode->nextNode = newNode;
		head = newNode;
	}

	else {
		newNode->nextNode = head->nextNode;
		head->nextNode = newNode;
		head = newNode;
	}
}

void LinkedList::remove(int n) {
	node* temp = head;

	for (int i = 0; i < n; i++) {
		temp = temp->nextNode;
	}

	if (temp->nextNode == head) {
		temp->nextNode = temp->nextNode->nextNode;
		head = temp;
	}
	else {
		temp->nextNode = temp->nextNode->nextNode;
	}
}

void LinkedList::showList() {

	if (head == NULL) {
		cout << -1 << '\n';
	}
	else {
		node* temp = head->nextNode;

		while (temp != head) {
			cout << temp->data << " ";
			temp = temp->nextNode;
		}
		cout << temp->data << "\n";
	}
}

int main() {

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		LinkedList s;
		for (int j = 0; j < 10; j++) {
			int number;
			cin >> number;
			s.addBack(number);
		}

		for (int k = 0; k < 3; k++) {
			string command;
			int number;

			cin >> command;
			cin >> number;
			s.remove(number);
		}
		s.showList();
	}
}