#include <iostream>
#include <cmath>

using namespace std;


int main () {
    int year;
    bool flag = false;

    while (!flag) {
        cin >> year;
        if (year == 0) {
            flag = true;
        } else {
            int exp = (year - 1960) / 10 + 2;

            int rhs = pow (2, exp);

            double temp = 0;

            int n = 1;
            while (temp < rhs) {
                temp += log2(n++);
            }

            cout << n - 2 << "\n";
        }
    }

    return 0;
}