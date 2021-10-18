#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int main () {
    int n;
    cin >> n;

    int arr1[n][n];
    int check[n][n];
    int temp[n][n];
    char result[n][n];
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            arr1[i][j] = 0;
            check[i][j] = 0;
            result[i][j] = ' ';
            temp[i][j] = 0;
        }
    }



    string input;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            char t;
            cin >> t;
            if (t == '.') arr1[i][j] = 1;
        }
    }

    cin >> input;

    
    int k = 0;

    int T = 4;

    while (T--) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (arr1[i][j] == 1) {
                    result[i][j] = input[k];
                    ++k;
                    if (check[i][j]) {
                        cout << "invalid grille\n";
                        return 0;
                    }
                    check[i][j] = 1;
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                temp[j][n-i-1] = arr1[i][j];
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                arr1[i][j] = temp[i][j];
            }
        }



    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!check[i][j]) {
                cout << "invalid grille\n";
                return 0;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << result[i][j];
        }
    }
    cout << "\n";

    return 0;
}