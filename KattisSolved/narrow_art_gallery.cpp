#include <iostream>
#include <utility>
#include <vector>
#include <climits>

using namespace std;

typedef pair<int, int> pr;

const int ROOM_MAX = 202;

int storage[ROOM_MAX][ROOM_MAX][3];

//  
int solve(const vector<pr>& rooms, int n, int k, char last = 'b') {
    //  base case
    if (n == rooms.size()) {
        if (k == 0) return 0;
        else return INT_MIN;
    }

    if (last == 'l') {
        if (storage[n][k][0] == -1) {
        storage[n][k][0] = max(
                (rooms[n].first + rooms[n].second + solve(rooms, n+1, k)),
                (rooms[n].second + solve(rooms, n+1, k-1, 'l'))
            );
        }
        return storage[n][k][0];
    } else if (last == 'r') {
        if (storage[n][k][1] == -1) {
            storage[n][k][1] = max(
                (rooms[n].first + rooms[n].second + solve(rooms, n+1, k)),
                (rooms[n].first + solve(rooms, n+1, k-1, 'r'))
            );
        }
        return storage[n][k][1];  
    } else {
        if (storage[n][k][2] == -1) {
            storage[n][k][2] = max(
                (rooms[n].first + rooms[n].second + solve(rooms, n+1, k)),
                max(
                    (rooms[n].first + solve(rooms, n+1, k-1, 'r')),
                    (rooms[n].second + solve(rooms, n+1, k-1, 'l'))
                )
            );
        }
        return storage[n][k][2];
    }
}


int main () {
    int N, k;
    cin >> N >> k;
    vector<pr> array;

    for (int i = 0; i < ROOM_MAX; ++i) {
        for (int j = 0; j < ROOM_MAX; ++j) {
            for (int k = 0; k < 3; ++k) {
                storage[i][j][k] = -1;
            }
        }
    }


    while (N--) {
        pr p;
        cin >> p.first >> p.second;
        array.push_back(p);
    }
    int a,b;
    cin >> a >> b;

    cout << solve(array, 0, k) << "\n";


    return 0;
}