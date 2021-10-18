#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


template<typename T>
void printv(const vector<T>& v) {
    for (auto i : v) {
        cout << i << " ";
    }
    cout << endl;
}

int main () {
    
    int n, h;
    cin >> n >> h;
    
    vector<int> top;
    vector<int> bottom;
    
    vector<int> h1(h, 0);
    vector<int> h2(h, 0);
    vector<int> height(h, 0);
    
    top.reserve(n/2);
    bottom.reserve(n/2);
    
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if (i % 2 == 0) {
            top.push_back(t);
        } else {
            bottom.push_back(t);
        }
    }
    
    sort(top.begin(), top.end());
    sort(bottom.begin(), bottom.end());
    
    
    for (int i = 0; i < h; ++i) {
        auto it1 = upper_bound(bottom.begin(), bottom.end(), i);
        h1[i] += (bottom.end() - it1);
    }
    int j = h-1;
    for (int i = 0; i < h; ++i) {
        auto it1 = upper_bound(top.begin(), top.end(), i);
        h2[j] += (top.end() - it1);
        --j;
    }
    
    for (int i = 0; i < h; i++) {
        height[i] = h1[i] + h2[i];
    }
    
    auto min = min_element(height.begin(), height.end());
    
    int cntr = count(height.begin(), height.end(), *min);
    
    cout << *min << " " << cntr << endl;
    
    return 0;
}
