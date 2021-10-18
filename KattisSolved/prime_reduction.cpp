#include <iostream>
#include <cmath>
#include <vector>
#include <ctime>
using namespace std;

typedef long long ll;

ll primeFact2(ll n) {
    ll ans = 0;
    bool prime = true;

    for (ll i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            ans += i;
            n /= i;
            prime = false;
        }
    }
    if (n > 1) 
        ans += n;
    return ans;
}


int main () {
    ll n; 
    cin >> n;
    while (n != 4) {
        int i = 0;
        bool flag = true;
        ll out = n;
        while (flag) {
            ++i;
            ll ans = primeFact2(out);
            if (ans == out) {
                ans = out;
                flag = false;
            } else {
                out = ans;
            }
        }
        cout << out << " " << i << endl;
        cin >> n;
    }
    return 0;
}
