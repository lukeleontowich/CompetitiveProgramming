#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    int n, e;
    cin >> n >> e;

    long long t = pow(2, e);

    string s1 = to_string(t);

    int cntr = 0;
    for (int i = 0; i <= n; ++i) {
        if (to_string(i).find(s1) != string::npos) {
            ++cntr;
        }
    }
    cout << cntr << "\n";
}