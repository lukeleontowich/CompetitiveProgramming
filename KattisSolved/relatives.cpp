#include <iostream>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
using namespace std;

typedef long long ll;

static const ll largest = 500000000; // roughly sqrt(billion)



template <typename T>
void printv(const vector<T>& v) {
    for (auto i : v) {
        cout << i << " ";
    }
    cout << endl;
}

void initPrimes(vector<ll>& v) {
    vector<bool> p(largest, 1);
    for (ll i = 2; i < largest; ++i) {
        if (p[i]) {
            v.push_back(i);
            for (ll j = i * i; j < largest; ) {
                p[j] = 0;
                j += i;
            }
        }
    }
}

void primeFactor(const vector<ll>& primes, vector<ll>& fact, ll n) {
    ll end = sqrt(n) + 1;
    for (ll i = 0; i < primes.size(); ++i) {
        if (primes[i] > end)
            break;
        if (n % primes[i] == 0) {
            fact.push_back(primes[i]);
        }
    }
    return;
}

void primeFactor2(vector<ll>& fact, ll n) {
    for (ll i = 2; i * i <= n; i++) {
        bool pushed = false;
        while (n % i == 0) {
            if (!pushed) {
                fact.push_back(i);
                pushed = true;
            }
            n /= i;
        }
    }
    if (n > 1)
        fact.push_back(n);
}

ll eulerTotient(const vector<ll>& fact, const ll& n) {
    if (fact.size() == 1)
        return n -1;
    ll ans = n;
    for (ll i = 0; i < fact.size(); ++i) {
        ans = ans - ans / fact[i];
    }
    return  ans;
}

int main () {
    ll n;
    while (cin >> n && n != 0) {
        vector<ll> fact;
        primeFactor2(fact, n);
        //cout << "fators: "; printv(fact);
        cout << eulerTotient(fact, n) << endl;
    }
    
    return 0;
}








