#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <string>
using namespace std;


vector<int>::iterator getLowerBound(vector<int>& v, int q) {
    auto it = v.begin();
    if (q < v[0]) return it;
    while (it != v.end()) {
        if (q < *it) {
            return --it;
        }
        it++;
    }
    return v.end()-1;
}

vector<int>::iterator getUpperBound(vector<int>& v, int q) {
    auto it = v.begin();
    while (it != v.end()) {
        if (q < *it) {
            return it;
        }
        it++;
    }
    return v.end()-1;
}

int main () {
    vector<int> arr;
    vector<int> result;
    
    string output;
    
    int cntr = 1;
    
    int n, m, t;
    while(cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> t;
            arr.push_back(t);
        }
    
        for (int i = 0; i < n-1; i++) {
            for (int j = i+1; j < n; j++) {
                result.push_back(arr[i]+arr[j]);
            }
        }
    
        sort(result.begin(), result.end());
    
        int q;
        cin >> q;
        vector<pair<int, int>> closest;
        pair<int, int> temp;
    
        for (int i = 0; i < q; i++) {
            cin >> t;
            temp.first = t;
            auto lb = getLowerBound(result, t);
            auto rb = getUpperBound(result, t);
            if (abs(t - *lb) < abs(t - *rb)) {
                temp.second = *lb;
                closest.push_back(temp);
            } else {
                temp.second = *rb;
                closest.push_back(temp);
            }
        }
        
        cout << "Case " << cntr++ << ":\n";
        for (int i = 0; i < closest.size(); i++) {
            cout << "Closest sum to " << closest[i].first
                 << " is " << closest[i].second << ".\n";
        }
    
        result.clear();
        closest.clear();
        arr.clear();
        cin.clear();
    }
    return 0;
}
