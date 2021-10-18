#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main () {
    int c;
    cin >> c;
    for (int i = 0; i < c ; ++i) {
        int n;
        cin >> n;
        vector<int> v;
        for (int j = 0; j < n; ++j) {
            int t;
            cin >> t;
            v.push_back(t);
        }
        double ave = 0;
        for (auto j : v) {
           ave += j;
        }
        ave /= double(n);
        int cntr = count_if(v.begin(), v.end(), [&ave](const int& a){
                                                if (a > ave) return 1;
                                                else return 0;});
        double ans = double(cntr) / double(n);
        ans *= 100.0;
        cout << fixed << setprecision(3) << ans << "%\n";
    }
    
    return 0;
}
