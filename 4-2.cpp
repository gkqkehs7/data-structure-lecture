
#include <iostream>
#include <string>
using namespace std;


struct stack {
    int arr[1000];
    int len;

    void init() {
        len = -1;
    }

    void push(int data) {
        arr[++len] = data;
    }

    bool empty() {
        return (len < 0);

    }

    int pop() {
        if (empty()) {
            return -1;
        }
        return arr[len--];
    }

    int size() {
        return len + 1;
    }

    int top() {
        if (empty()) {
            return -1;
        }
        else {
            return arr[len];
        }
    }
};
int main()
{
    stack s;
    s.init();
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {

        string command;
        cin >> command;

        if (command[0] == 'e') {
            cout << s.empty() << '\n';
        }
        else if (command[0] == 't') {
            cout << s.top() << '\n';
        }
        else if (command[0] == 'p') {
            if (command[1] == 'u') {
                int number;
                cin >> number;

                s.push(number);
            }
            else {
                cout << s.pop() << '\n';
            }
        }
        else {
            cout << s.size() << '\n';
        }
    }
}


