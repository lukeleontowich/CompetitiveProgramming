#include <set>
#include <iostream>
#include <cmath>

using namespace std;

void print(const multiset<int>& array) {
    for (auto it = array.begin(); it != array.end(); ++it) {
        cout << *it << " ";
    }
    cout << "\n";
}

void correct(multiset<int>& lower, multiset<int>& higher) {
    if (lower.size() + 1 < higher.size()) {
        auto element = *(higher.begin());
        lower.insert(element);
        higher.erase(higher.begin());
    } else if (higher.size() + 1 < lower.size()) {
        auto element = *(--lower.end());
        higher.insert(element);
        lower.erase(--lower.end());
    }
}

long long insert(int element, multiset<int>& lower, multiset<int>& higher) {
    auto l = *(--lower.end());
    auto h = *(higher.begin());
    if (element > l) {
        higher.insert(element);
    } else {
        lower.insert(element);
    }
    correct(lower, higher);

    if (lower.size() == higher.size()) {
        return (*(higher.begin()) + *(--lower.end())) / 2;
    } else if (lower.size() > higher.size()) {
        return *(--lower.end());
    } else {
        return *(higher.begin());
    }

}




int main() {

    int T;
    cin >> T;
    while (T--) {
        int cntr = 0;
        int N;
        cin >> N;
        long long ans = 0;
        if (N == 1) {
            int p; 
            cin >> p;
            ans = p;
            N--;
        }
        multiset<int> lower;
        multiset<int> higher;

        while (N--) {
            int t;
            if (cntr == 0) {
                int t1, t2;
                cin >> t1 >> t2;
                --N;
                if (t1 < t2) {
                    lower.insert(t1);
                    higher.insert(t2);
                    ans += t1;
                    ans += (t2 + t1) / 2;
                } else {
                    lower.insert(t2);
                    higher.insert(t1);
                    ans += t1;
                    ans += (t1 + t2) / 2;
                }
                cntr++;
            } else {
                cin >> t;
                long long temp;
                temp = insert(t, lower, higher);
                ans += temp;
            }
        }
        cout << ans << "\n";
    }


    return 0;
}
