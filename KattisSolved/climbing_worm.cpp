#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int a, b, h;
    cin >> a >> b >> h;

    int worm = 0;
    int cntr = 0;

    while (worm < h) {
        worm += a;
        if (worm < h) {
            worm -= b;
        }
        ++cntr;
    }

    cout << cntr << "\n";

    return 0;
}