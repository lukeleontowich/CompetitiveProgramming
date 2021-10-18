#include <utility>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

void print(const map<char, bool[10]>& notes) {
    cout << "   ";
    for (unsigned int i = 1; i < 11; ++i) {
        cout << i << " ";
    }
    cout << "\n";
    for (auto it = notes.begin(); it != notes.end(); ++it) {
        cout << it->first << ": ";
        for (unsigned int i = 0; i < 10; ++i) {
            cout << it->second[i] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void initMap(map<char, bool[10]>& notes) {
    //  c;
    for (unsigned int i = 1; i <= 10; ++i) {
        if (i == 2 || i == 3 || i == 4 || i == 7 || i == 8 || i == 9 || i == 10)
            notes['c'][i-1] = true;
        else 
            notes['c'][i-1] = false;
    }

    //  'd'
    for (unsigned int i = 1; i <= 10; ++i) {
        if (i == 2 || i == 3 || i == 4 || i == 7 || i == 8 || i == 9)
            notes['d'][i-1] = true;
        else 
            notes['d'][i-1] = false;
    }

    //  'e'
    for (unsigned int i = 1; i <= 10; ++i) {
        if (i == 2 || i == 3 || i == 4 || i == 7 || i == 8)
            notes['e'][i-1] = true;
        else 
            notes['e'][i-1] = false;
    }

    //  'f'
    for (unsigned int i = 1; i <= 10; ++i) {
        if (i == 2 || i == 3 || i == 4 || i == 7)
            notes['f'][i-1] = true;
        else 
            notes['f'][i-1] = false;
    }

    //  'g'
    for (unsigned int i = 1; i <= 10; ++i) {
        if (i == 2 || i == 3 || i == 4)
            notes['g'][i-1] = true;
        else 
            notes['g'][i-1] = false;
    }

    //  'a'
    for (unsigned int i = 1; i <= 10; ++i) {
        if (i == 2 || i == 3)
            notes['a'][i-1] = true;
        else 
            notes['a'][i-1] = false;
    }

    //  'b'
    for (unsigned int i = 1; i <= 10; ++i) {
        if (i == 2)
            notes['b'][i-1] = true;
        else 
            notes['b'][i-1] = false;
    }

    //  C
    for (unsigned int i = 1; i <= 10; ++i) {
        if (i == 3)
            notes['C'][i-1] = true;
        else 
            notes['C'][i-1] = false;
    }

    //  D
    for (unsigned int i = 1; i <= 10; ++i) {
        if (i == 1 || i == 2 || i == 3 || i == 4 || i == 7 || i == 8 || i == 9)
            notes['D'][i-1] = true;
        else 
            notes['D'][i-1] = false;
    }

    //  E
    for (unsigned int i = 1; i <= 10; ++i) {
        if (i == 1 || i == 2 || i == 3 || i == 4 || i == 7 || i == 8)
            notes['E'][i-1] = true;
        else 
            notes['E'][i-1] = false;
    }

    //  F
    for (unsigned int i = 1; i <= 10; ++i) {
        if (i == 1 || i == 2 || i == 3 || i == 4 || i == 7)
            notes['F'][i-1] = true;
        else 
            notes['F'][i-1] = false;
    }

    //  G
    for (unsigned int i = 1; i <= 10; ++i) {
        if (i == 1 || i == 2 || i == 3 || i == 4)
            notes['G'][i-1] = true;
        else 
            notes['G'][i-1] = false;
    }

    //  A
    for (unsigned int i = 1; i <= 10; ++i) {
        if (i == 1 || i == 2 || i == 3)
            notes['A'][i-1] = true;
        else 
            notes['A'][i-1] = false;
    }

    //  B
    for (unsigned int i = 1; i <= 10; ++i) {
        if (i == 1 || i == 2)
            notes['B'][i-1] = true;
        else 
            notes['B'][i-1] = false;
    }
}

int main() {
    map<char, bool[10]> notes;

    initMap(notes);

    int T;
    cin >> T;

    string empty;

    getline(cin, empty);

    while (T--) {
        bool fingers_state[10];
        fill(fingers_state, fingers_state + 10, false);

        int fingers_cntr[10];
        fill(fingers_cntr, fingers_cntr + 10, 0);

        string s;
        getline(cin, s);

        for (unsigned int i = 0; i < s.size(); i++) {
            for (unsigned int j = 0; j < 10; ++j) {
                //  if finger need to press key
                if (notes[s[i]][j]) {
                    //  check if finger is not pressing key
                    if (!fingers_state[j]) {
                        //  press key
                        fingers_state[j] = true;

                        //  add to counter
                        fingers_cntr[j]++;
                    }
                //  else release key    
                } else {
                    fingers_state[j] = false;
                }


            }
        }
        for (unsigned int i = 0; i < 10; ++i) {
            cout << fingers_cntr[i] << " ";
        }
        cout << "\n";
    }

    return 0;

}


