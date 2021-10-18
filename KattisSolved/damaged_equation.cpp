#include <iostream>

using namespace std;

int main () {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    bool ok = false;

    if (a * b == c * d) {
        ok = true;
        cout << a << " * " << b << " = " << c << " * " << d << "\n";
    }
    if (a * b == c + d) {
        ok = true;
        cout << a << " * " << b << " = " << c << " + " << d << "\n";
    }
    if (a * b == c - d) {
        ok = true;
        cout << a << " * " << b << " = " << c << " - " << d << "\n";
    }
    if (d != 0) {
        if (a * b == c / d) {
            cout << a << " * " << b << " = " << c << " / " << d << "\n";
            ok = true;
        }
    }

    if (a + b == c * d) {
        ok = true;
        cout << a << " + " << b << " = " << c << " * " << d << "\n";
    }
    if (a + b == c + d) {
        ok = true;
        cout << a << " + " << b << " = " << c << " + " << d << "\n";
    }
    if (a + b == c - d) {
        ok = true;
        cout << a << " + " << b << " = " << c << " - " << d << "\n";
    }
    if (d != 0 ) {
        if (a + b == c / d) {
            ok = true;
            cout << a << " + " << b << " = " << c << " / " << d << "\n";
        }
    }
    
    if (a - b == c * d) {
        ok = true;
        cout << a << " - " << b << " = " << c << " * " << d << "\n";
    }
    if (a - b == c + d) {
        ok = true;
        cout << a << " - " << b << " = " << c << " + " << d << "\n";
    }
    if (a - b == c - d) {
        ok = true;
        cout << a << " - " << b << " = " << c << " - " << d << "\n";
    }
    if (d != 0) {
        if (a - b == c / d) {
            ok = true;
            cout << a << " - " << b << " = " << c << " / " << d << "\n";
        }
    }

    if (b != 0) {
        if (a / b == c * d) {
            ok = true;
            cout << a << " / " << b << " = " << c << " * " << d << "\n";
        }
    }
    if (b != 0) {
        if (a / b == c + d) {
            ok = true;
            cout << a << " / " << b << " = " << c << " + " << d << "\n";
        }
    }
    if (b != 0) {
        if (a / b == c - d) {
            ok = true;
            cout << a << " / " << b << " = " << c << " - " << d << "\n";
        }
    }
    if (b != 0 && d != 0) {
        if (a / b == c / d) {
            ok = true;
            cout << a << " / " << b << " = " << c << " / " << d << "\n";
        }
    }

    if (!ok) {
        cout << "problems ahead\n";
    }

    return 0;
}