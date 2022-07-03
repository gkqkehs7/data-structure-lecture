#include <iostream>
#include <string>
using namespace std;


class Queue {
public:

	Queue(int size) {
		Q = new int[size];
		capacity = size;
		f = 0;
		r = -1;
		n = 0;
	}

	int size() {
		return n;
	}
	bool isEmpty() {
		if (size() == 0) {
			return 1;
		}
		else {
			return 0;
		}
	}
	void front() {
		if (size() == 0) {
			cout << "Empty" << "\n";
		}
		else {
			cout << Q[f] << "\n";
		}

	}
	void rear() {
		if (size() == 0) {
			cout << "Empty" << "\n";
		}
		else {
			cout << Q[r] << "\n";
		}

	}

	void enqueue(int data) {
		if (size() == capacity) {
			cout << "Full" << "\n";
		}
		else {
			r = (r + 1) % capacity;
			Q[r] = data;
			n = n + 1;
		}

	}
	void dequeue() {
		if (size() == 0) {
			cout << "Empty" << "\n";
		}
		else {
			cout << Q[f] << "\n";
			f = (f + 1) % capacity;
			n = n - 1;
		}
	}

	int* Q;
	int capacity;
	int f;
	int r;
	int n;
};

int main() {
	int size;
	cin >> size;
	Queue q(size);

	int cmdNum;
	cin >> cmdNum;

	while (cmdNum--) {
		string cmd;
		cin >> cmd;

		if (cmd == "enqueue") {
			int input;
			cin >> input;
			q.enqueue(input);
		}
		else if (cmd == "dequeue") {
			q.dequeue();
		}
		else if (cmd == "size") {
			cout << q.size() << "\n";
		}
		else if (cmd == "isEmpty") {
			cout << q.isEmpty() << "\n";
		}
		else if (cmd == "front") {
			q.front();
		}
		else if (cmd == "rear") {
			q.rear();
		}
	}
}