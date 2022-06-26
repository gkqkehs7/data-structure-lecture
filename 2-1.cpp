#include <iostream>
#include <string>

int main()
{
    int arr[10000] = { 0 };

    int M;
    std::cin >> M;

    int len = 0;
    for (int i = 0; i < M; i++) {
        std::string command;
        std::cin >> command;

        if (command[0] == 'a') {
            if (command[1] == 't') {
                int a;
                std::cin >> a;

                if (arr[a] == 0) {
                    std::cout << 0 << '\n';
                }
                else {
                    std::cout << arr[a] << '\n';
                }
            }
            else {
                int a, b;
                std::cin >> a >> b;

                if (len == 0) {
                    arr[0] = b;
                }
                else if (arr[a] == 0) {
                    arr[len] = b;
                }
                else {
                    for (int k = len; k > a; k--) {
                        arr[k] = arr[k - 1];
                    }
                    arr[a] = b;
                }
                len++;
            }

        }
        else if (command[0] == 's') {
            int a, b;
            std::cin >> a >> b;

            if (arr[a] == 0) {
                std::cout << 0 << '\n';

            }
            else {
                arr[a] = b;
            }

        }
    
    };
}

