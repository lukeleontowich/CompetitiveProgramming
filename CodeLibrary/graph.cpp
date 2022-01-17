#include <iostream>
#include <vector>
#include <cassert>
#include <queue>
#include <algorithm>
#include <stack>

using namespace std;

template <typename T>
class Graph {
public:
    Graph(const int& n) {
        assert(n > 1);
        N = n;
        adj_list = new vector<T>[N];
        for (int i = 0; i < N; ++i) {
            adj_list[i].reserve(N);
        }
    } 
    ~Graph() {
        if (adj_list != nullptr) {
            delete [] adj_list;
        }
    }

    void addEdge(const T& src, const T& dest) {
        assert(src >= 0 && src < N && dest >= 0 && dest < N);
        adj_list[src].push_back(dest);
    }

    bool BFS(const T& src, const T& dest) {
        bool visited[N];
        fill (visited, visited+N, false);

        queue<T> q;

        visited[src] = true;
        q.push(src);

        while (!q.empty()) {
            auto u = q.front();

            q.pop();

            for (auto x : adj_list[u]) {
                if (!visited[x]) {
                    visited[x] = true;
                    q.push(x);
                }
            }
        }
        return visited[dest];
    }

    bool DFS(const T& src, const T& dest) {
        bool visited[N];
        fill (visited, visited + N, false);
        stack<T> s;
        s.push(src);
        visited[src] = true;
        while (!s.empty()) {
            auto u = s.top();
            s.pop();
            for (auto x : adj_list[u]) {
                if (!visited[x]) {
                    s.push(x);
                    visited[x] = true;
                }
            }
        }
        return visited[dest];
    }




private:
    vector<T>* adj_list = nullptr;
    int N;
};

int main () {
    Graph<int> g(7);


    return 0;
}