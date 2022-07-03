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
	~Queue()
	{
		delete[] Q;
	}
	int size() {
		return n;
	}

	void enqueue(int data) {
		r = (r + 1) % capacity;
		Q[r] = data;
		n = n + 1;

	}
	int dequeue() {
		int temp = f;
		f = (f + 1) % capacity;
		n = n - 1;
		return Q[temp];
	}

	int* Q;
	int capacity;
	int f;
	int r;
	int n;
};

int main() {
	int cmdNum;
	cin >> cmdNum;

	for (int i = 0; i < cmdNum; i++) {
		int size;
		cin >> size;
		Queue q1(size);
		Queue q2(size);

		int p1_s = 0;
		int p2_s = 0;

		for (int j = 0; j < size; j++) {
			int input;
			cin >> input;
			q1.enqueue(input);
		}

		for (int j = 0; j < size; j++) {
			int input;
			cin >> input;

			q2.enqueue(input);
		}

		int p1_bonus = 0;
		int p2_bonus = 0;
		for (int j = 0; j < size; j++) {
			int p1 = q1.dequeue() + p1_bonus;
			int p2 = q2.dequeue() + p2_bonus;

			if (p1 > p2) {
				p1_bonus = p1 - p2 -1;
				p2_bonus = 0;
				p1_s++;
			}
			else if (p1 < p2) {
				p1_bonus = 0;
				p2_bonus = p2 - p1 - 1;
				p2_s++;
			}
			else {
				p1_bonus = 0;
				p2_bonus = 0;
			}
		}

		if (p1_s > p2_s) {
			cout << 1 << "\n";
		}
		else if (p1_s < p2_s) {
			cout << 2 << "\n";
		}
		else {
			cout << 0 << "\n";
		}
	}

	return 0;
}