#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <vector>
#include <cmath>
using namespace std;

#define shift 48



string closest(const vector<int>* adj_list, int index, int num, string str) {
    int lb = adj_list[index][0];
    int ub = adj_list[index][adj_list[index].size()-1];

    //  get lower and upper bounds
    for (int i = 0; i < adj_list[index].size(); i++) {
        if (num - adj_list[index][i] > 0) {
            lb = adj_list[index][i];
        } else {
            ub = adj_list[index][i];
            break;
        }
    }

    //  Get the strings
    int lb_max = adj_list[lb][adj_list[lb].size()-1];
    int ub_min = adj_list[ub][0];
    
    string lb_str;
    lb_str.push_back(lb+shift);
    
    string ub_str;
    ub_str.push_back(ub+shift);

    
    for (int i = 0; i < str.size()-1; i++) {
        lb_str.push_back(lb_max + shift);
        ub_str.push_back(ub_min + shift);
    }

    
    if ( abs(stoi(str) - stoi(lb_str)) < abs(stoi(ub_str) - stoi(str)) ) {
        return lb_str;
     } else {
        return ub_str;
     }
    
}

string closest2(int index, int size) {
    string str;
    if (index == 3) {
        str.push_back('2');
    } else if (index == 6) {
        str.push_back('5');     
    } else if (index == 9) {
        str.push_back('8');
    }
    for (int i =0; i < size-1; i++) {
        str.push_back('9');
    }
    return str;
}

int main() {
    vector<int> adj_list[10];
    
    //  zero
    adj_list[0].push_back(0);
    
    //  one
    for (int i = 0; i < 10; i++) {
        adj_list[1].push_back(i);
    }


    //  two
   for (int i = 0; i < 10; i++) {
      if (i != 1 && i != 4 && i != 7)
            adj_list[2].push_back(i);
   }


    //  three
    for (int i = 0; i < 10; i++) {
        if (i == 6 || i == 9 || i == 3)
            adj_list[3].push_back(i);
    }
    
    //  four
    for (int i = 0; i < 10; i++) {
        if (i != 1 && i != 2 && i != 3)
            adj_list[4].push_back(i);
    }
    
    //  five
    for (int i = 0; i < 10; i++) {
        if (i != 1 && i != 2 && i != 3 && i != 4 && i != 7)
            adj_list[5].push_back(i);
    }

    //  six
    for (int i = 0; i < 10; i++) {
        if (i == 6 || i == 9)
            adj_list[6].push_back(i);
    }
    
    // seven
    for (int i = 0; i < 10; i++) {
        if (i == 7 || i == 8 || i == 9 || i == 0)
            adj_list[7].push_back(i);
    }

    //  eight
    for (int i = 0; i < 10; i++) {
        if (i == 8 || i == 9 || i == 0)
            adj_list[8].push_back(i);
    }
    
    //  nine
    adj_list[9].push_back(9);
    
    
    //  start
    int t;

    
    cin >> t;
    
    for (int i = 0 ; i < t; i++) {
        string str;     
        cin >> str;
        //cout << str << " ";
        
        vector<char> result;
        result.push_back(str[0]);
        
        if (str == "106" || str == "107" || str == "108" || str == "109") {
            str = "110";
        } else {
        
            for (int i = 0; i < str.size() -1; i++) {
                int index = (int)(str[i])-shift;
            
                if (binary_search(adj_list[index].begin(),
                                  adj_list[index].end(),
                                  (int)(str[i+1])-shift)) {       
                    result.push_back(str[i+1]);
                                 
                } else {
                    string temp = closest(adj_list, index,
                                          (int)(str[i+1])-shift,
                                          str.substr(i+1));
                    if (index == 3 || index == 6 || index == 9) {
                     
                        string temp2 = closest2( index, str.size()-i );
                        string temp3(str);
                    
                        temp3.replace(temp3.begin()+i+1, temp3.end(), temp);
                    
                        string temp4(str);
                        temp4.replace(temp4.begin()+i, temp4.end(), temp2);
                    
                        if ( abs(stoi(temp3) - stoi(str)) < abs(stoi(temp4) - stoi(str)))
                            str = temp3;
                        else 
                            str = temp4;
                    } else {   

                        str.replace(str.begin()+i+1, str.end(), temp);
                    }
                    break;
                }
            }
        }
        cout << str << endl;
        
    }
    
    
    return 0;
    
}
