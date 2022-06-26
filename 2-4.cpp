#include <iostream>
#include <string>
#include<cmath>

int main()
{

    int M;

    std::cin >> M;


    for (int i = 0; i < M; i++) {
        int arr[100] = { 0 };
        int k = 0;
        int j = 0;
        int c = 0;
        int k_count = 0;
        int j_count = 0;
        int c_count = 0;
        int N;
        std::cin >> N;

        for (int i = 0; i < N; i++) {
            int money;
            std::cin >> money;
            arr[i] = money;
        }

        for (int i = 0; i < N; i++) {

            if (i % 3 == 0) {
                if (arr[i] != 0) {
                    k += arr[i];
                    k_count++;
                }

            }
            else if (i % 3 == 1) {
                if (arr[i] != 0) {
                    j += arr[i];
                    j_count++;
                }
            }
            else {
                if (arr[i] != 0) {
                    c += arr[i];
                    c_count++;
                }
            }
        }

        int answer_k;
        int answer_j;
        int answer_c;

        if (k_count == 0) {
            answer_k = 0;
        }
        else {
            answer_k = floor(k / k_count);
        }

        if (j_count == 0) {
            answer_j = 0;
        }
        else {
            answer_j = floor(j / j_count);
        }

        if (c_count == 0) {
            answer_c = 0;
        }
        else {
            answer_c = floor(c / c_count);
        }
        std::cout << k << ' ' << j << ' ' << c << '\n';
        std::cout << answer_k << ' ' << answer_j << ' ' << answer_c << '\n';
    }
}

