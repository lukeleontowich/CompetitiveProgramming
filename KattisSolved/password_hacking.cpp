#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int getInput() {
    string s;
    cin >> s;
    if (s.at(0) == '1') return 1;
    else return stoi(s.substr(2, 4));
}



int main () {
    vector<int> arr;
    int n;
    cin >> n;
    string nothing;
    for (int i = 0; i < n; ++i) {
        cin >> nothing;
        arr.push_back(getInput());
    }
    sort(arr.begin(), arr.end(), 
        [](const int& x, const int& y)->bool{return x > y;});
    
    int den = 10000;  
    double neg = 1;
    double result = 0;

    if (arr.at(0) == 1) {
        cout << "1.0000\n";
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        int num = arr[i];
        double p = double(num) / double(den);
        result += (i + 1) * p * neg;
        neg *= 1.0 - p;
        den -= num;
    }
    cout << fixed << setprecision(10);
    cout << result << "\n";
    

    return 0;
}
