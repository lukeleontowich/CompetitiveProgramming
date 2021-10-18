#include <iostream>
#include <list>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

void print(const list<string>& l) {
    for (auto it = l.begin(); it != l.end(); ++it) {
        cout << *it << " ";
    }
    cout << "\n";
}

int main () {
    int T;
    cin >> T;
    string tempy;
    getline(cin, tempy);
    while (T--) {
        string temp;
        
        getline(cin, temp);
        stringstream stream(temp);
        string s;
        list<string> array;
        while (stream >> s) {
            array.push_back(s);
        }
        string line;

        while (getline(cin, line)) {
            if (line == "what does the fox say?") break;
            stringstream stream2(line);
            string t1, t2, t;
            stream2 >> t1 >> t2 >> t;
            

            array.remove_if( [&t](const string& s1)->bool{
                return t == s1;
            });
        }
        print(array);

      
        


    }

}