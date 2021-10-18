#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

typedef long long ll;

// 2'147'483'648
constexpr ll max = 2147483648;

bool isPrime(const ll& n) {
    ll end = sqrt(n) + 1;
    bool prime = true;
    for (ll i = 2; i < end; ++i) {
        if (n % i == 0) {
            prime = false;
            break;
        }
            
    }
    return prime;
}

int main () {
    ll n;
    cin >> n;
    while(n) {
        ll original = n;
        n *= 2;
        while (!isPrime(++n)) ;
        cout << n;
        if (!isPrime(original)) {
            cout << " (" << original << " is not prime)";
        }
        cout << endl;
        cin >> n;
    }
    return 0;
}
