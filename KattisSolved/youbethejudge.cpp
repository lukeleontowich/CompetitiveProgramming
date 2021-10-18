#include <iostream>
#include <string>
#include <vector>

using namespace std;

const long long MAX = 1e9;

vector<string> numbers;


bool isPrime(int n) {
    if (n <= 1)
        return false;
    for (int i = 2; (long long)i*i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}

bool checkInput(const string& s) {
    if (s.size() > 10) return false;
    if (s.empty()) return false;
    if (s[0] == '0') return false;
    for (auto x : s) {
        if (!isdigit(x)) return false;
    }
    numbers.push_back(s);
    return true;
}

int main () {
    string s;
    bool ok = true;

    int cntr = 0;
    while (cin >> s) {
        if (!checkInput(s)) ok =false;
        ++cntr;
    }

    if (cntr != 3) ok = false;

    if (numbers.size() == 3) {
        if (numbers[0].size() > 10 || numbers[1].size() > 10 || numbers[2].size() > 10) {
            ok = false;
        } else {
            if (stoll(numbers[0]) <= 3) ok =false;
            if (stoll(numbers[0]) > MAX) ok = false;

            if (stoll(numbers[0]) % 2 == 1) ok = false;
            if (!isPrime(stoll(numbers[1]))) ok = false;
            if (!isPrime(stoll(numbers[2]))) ok = false;

            long long ans = stoll(numbers[1]) + stoll(numbers[2]);
            if (ans != stoll(numbers[0])) ok = false;
        }

    } else {
        ok = false;
    }
    

    if (ok) cout << "1\n";
    else cout << "0\n";

    return 0;
}