#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;

int main () {
    vector<int> shop;
    vector<int> joe;
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        shop.push_back(t);
    }
    
    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        joe.push_back(t);
    }
    
    
    sort(shop.begin(), shop.end());
    
    //sort(joe.begin(), joe.end());
    
   ll waste = 0;
    
    for (int i = 0; i < joe.size(); i++) {
        auto it = lower_bound(shop.begin(), shop.end(), joe[i]);
        if (*it != joe[i]) {
            waste += abs(*it - joe[i]);
        }
    }
    
    cout << waste << endl;

    
    return 0;
}
