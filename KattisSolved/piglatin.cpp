#include <string>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

bool isVowel(const char& s) {
    if (s == 'a' || s == 'e' || s == 'i' || s == 'o' ||
        s == 'u' || s == 'y') return true;
    else return false;
}

void latinize(string& s) {
    if (!s.empty()) {
        if (isVowel(s[0])) {
            s.append("yay");
        } else {
            size_t len = 0;
            string temp;
            for (auto x : s) {
                if (!isVowel(x)) {
                    ++len;
                    temp += x;
                } else {
                    break;
                }
            }
            s.erase(0, len);
            s += temp;
            s += "ay";
        }
    }


}

int main() {
    string s;
    
    while (getline(cin, s)) {
        stringstream strm(s);
        string str;
        while (strm >> str) {
            latinize(str);
            cout << str << " ";
        }
        cout << "\n";
    }


    return 0;
}