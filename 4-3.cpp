
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
};
int main()
{
   
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {

        stack s;
        s.init();
        string command;
        cin >> command;

        for (int j = 0; j < command.size(); j++) {

            if (command[j] == '*') {
                int a = s.pop();
                int b = s.pop();

                s.push(a * b);
            } else  if (command[j] == '+') {
                int a = s.pop();
                int b = s.pop();

                s.push(a + b);
            } else  if (command[j] == '-') {
                int b = s.pop();
                int a = s.pop();

                s.push(a - b);
            }
            else {
                s.push(command[j] - '0');
            }
        }

        cout << s.pop() << '\n';
    }
}


