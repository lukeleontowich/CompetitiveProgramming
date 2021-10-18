#include <iostream>
#include <set>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cmath>

using namespace std;

void print(const vector<int>& v) {
    for (auto x : v) cout << x << " ";
    cout << "\n";
}
void prints(const multiset<int>& s) {
    for (auto it = s.begin(); it != s.end(); ++it) {
        cout << *it << " ";
    }
    cout << "\n";
}

int main () {
    string line;
    while (getline(cin, line)) {
        stringstream stream(line);
        int t;
        vector<int> v;
        multiset<int> st;

        while (stream >> t) {
            v.push_back(t);
        }

        for (unsigned i = 0; i < v.size() - 1; ++i) {
            for (unsigned j = i + 1; j < v.size(); ++j) {
                st.insert(abs(v[j] - v[i]));
            }
        }

        vector<int> missing;
        bool not_ruler = false;
   
        for (unsigned i = 1; i < *(--st.end()); ++i) {
            int cntr = count(st.begin(), st.end(), i);
            if (cntr > 1) {
                not_ruler = true;
                break;
            } else if (cntr == 0) {
                missing.push_back(i);
            }
        }

        if (not_ruler) {
            cout << "not a ruler\n";
        } else if (missing.empty()) {
            cout << "perfect\n";
        } else {
            cout << "missing ";
            print(missing);
        }
    }

    return 0;
}