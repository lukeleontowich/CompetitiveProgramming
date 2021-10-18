#include <iostream>
#include <vector>
using namespace std;

typedef unsigned long long ll;

static const int SIZE = 10002;

static const ll mod = 1e9 + 7;

int main () {
    ll arr[SIZE] = {0};
    vector<int> solutions;
    solutions.reserve(100);
    
    arr[0] = 1;
    arr[1] = 1;
    
    for (int i = 2; i < SIZE; ++i) {
        arr[i-1] %= mod;
        arr[i-2] %= mod;
        arr[i] = arr[i-1] + arr[i-2];
        arr[i] %= mod;
    }
    
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        solutions.push_back(n+1);
    }
    
    for (int i = 0; i < solutions.size(); ++i) {
        cout << arr[solutions.at(i)] << endl;
    }
    
    return 0;
}

