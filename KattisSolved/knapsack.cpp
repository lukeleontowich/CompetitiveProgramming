#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pr;


void printa(int* arr, int n) {
    for (int i = 0; i < n+1; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main () {
    int c;
    while (cin >> c) {
        int n;
        cin >> n;
        int arr[n+1][c+1];
        for (int i = 0; i < n+1; ++i) {
            for (int j = 0; j < c+1; ++j) {
                arr[i][j] = 0;
            }
        }
        
        int varr[n+1];
        int warr[n+1];
        varr[0] = 0;
        warr[0] = 0;
        
        for (int i = 1; i <= n; ++i) {
            int v, w;
            cin >> v >> w;
            varr[i] = v;
            warr[i] = w;
        }
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= c; ++j) {
                if (warr[i] > j) {
                    arr[i][j] = arr[i-1][j];
                } else {
                    arr[i][j] = max( arr[i-1][j], arr[i-1][j-warr[i]] + varr[i]);
                }
            }
        }   
        int x = n;
        int cntr = 0;
        int weight = c;
        bool flag = false;
        vector<int> v;
        while (!flag) {
            if (arr[x][weight] > arr[x-1][weight]) {
                ++cntr;
                v.push_back(x-1);
                weight -= warr[x];
                --x;
            } else {
                --x;
            }
            if (weight <= 0)
                flag = true;
            if (x <= 0)
                flag = true;
        }
        cout << cntr << "\n";
        for (auto i : v) {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
