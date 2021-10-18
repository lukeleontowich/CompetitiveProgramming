#include <iostream>
#include <map>
#include <string>
using namespace std;


int main () {
    int T;
    cin >> T;
    while (T--) {
        map<string, int> m;
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            string t1, t2;
            cin >> t1 >> t2;
            m[t2]++;
        }
          
        int ans = 1;
        for (auto it = m.begin(); it != m.end(); ++it) {
            ++it->second;
            ans *= it->second;
        }
        cout << ans - 1 << endl;
   }

    return 0;
}
