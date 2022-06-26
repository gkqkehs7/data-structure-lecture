#include <iostream>
#include <string>

using namespace std;

int main() {
	int arr[10000] = { 0 };

	int N;
	cin >> N;
	int len = 0;
	for (int i = 0; i < N; i++) {

		string command;
		cin >> command;

		if (command[0] == 'a') {
			if (command[1] == 't') {
				int number;
				cin >> number;

				if (arr[number] == 0) {
					cout << 0 << '\n';
				}
				else {
					cout << arr[number] << '\n';
				}
			}
			else {
				int a, b;
				cin >> a >> b;
				if (len == 0) {
					arr[0] = b;
				}
				else if (arr[a] == 0) {
					arr[len] = b;
				}
				else {

					for (int j = len; j > a; j--) {
						arr[j] = arr[j - 1];
					}
					arr[a] = b;
				}
				len++;
			}
		}
		else if (command[0] == 's') {
			int a, b;
			cin >> a >> b;

			if (len == 0) {
				cout << 0 << '\n';
			}
			else {
				arr[a] = b;
			}

		}
		else if (command[0] == 'r') {
			int a;
			cin >> a;

			cout << arr[a] << '\n';

			if (arr[a] == 0) {
				cout << 0 << '\n';
			}
			else {
				for (int j = a; j < len; j++) {
					arr[j] = arr[j + 1];
				}
				len--;
			}

		}
		else {

			if (len == 0) {
				cout << 0 << '\n';
			}
			else {
				for (int k = 0; k < len; k++) {
					cout << arr[k] << ' ';
				}
			}
		}
	}
}
