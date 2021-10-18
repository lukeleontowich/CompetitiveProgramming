#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    

    int T;
    cin >> T;

    while (T--) {
        multiset<int> godzilla;
        multiset<int> mgodzilla;

        int Ng, Nm;
        cin >> Ng >> Nm;

        //  fill godzilla army
        for (int i = 0; i < Ng; ++i) {
            int t;
            cin >> t;
            godzilla.insert(t);
        }

        //  fill mecha godzilla army
        for (int i = 0; i < Nm; i++) {
            int t;
            cin >> t;
            mgodzilla.insert(t);
        }


        while (!godzilla.empty() && !mgodzilla.empty()) {
            if (*(godzilla.begin()) < *(mgodzilla.begin())) {
                godzilla.erase(godzilla.begin());
            } else {
                mgodzilla.erase(mgodzilla.begin());
            }
        }

        if (!godzilla.empty() && mgodzilla.empty()) {
            cout << "Godzilla\n";
        } else if (godzilla.empty() && !mgodzilla.empty()) {
            cout << "MechaGodzilla\n";
        } else {
            cout << "uncertain\n";
        }
    }

}
