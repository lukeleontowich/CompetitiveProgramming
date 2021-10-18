
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;



int main () {
    string tree;
    vector<string> trees;
    typedef pair<string, int> output;
    int temp;
    while (getline(cin, tree) && !tree.empty()) {
        if (tree[0] != ' ' && tree[tree.size() -1] != ' ' && tree.size() <= 20) {
            trees.push_back(tree);
        }
    }

    sort(trees.begin(), trees.end());
    int cntr = 1;
    int  i  = 0;
    double num_trees = trees.size();

    for (int j = 1; j < trees.size(); j++) {
        if (trees[i] == trees[j]) {
            cntr++;
        }
        else {
            cout << trees[i] << " " << cntr / num_trees * 100 << endl;
            i = j;
            cntr = 1;
        }
    }
    cout << trees[trees.size()-1] << " " << cntr / num_trees * 100 << endl;
    return 0;
}