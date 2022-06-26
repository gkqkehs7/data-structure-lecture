#include <iostream>
#include <string>

int main()
{
 
    int M;

    std::cin >> M;


    for (int i = 0; i < M; i++) {
        int arr[100] = { 0 };
        int k = 0;
        int j = 0;
        int c = 0;
        int N;
        std::cin >> N;

        for (int i = 0; i < N; i++) {
            int money;
            std::cin >> money;
            arr[i] = money;
        }

        for (int i = 0; i < N; i++) {
          
            if (i % 3 == 0) {
                k += arr[i];
            }
            else if (i % 3 == 1) {
                j += arr[i];
            }
            else {
                c += arr[i];
            }
        }

        std::cout << k << ' ' << j << ' ' << c << '\n';
    }
}

