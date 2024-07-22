#include <bits/stdc++.h>

using namespace std;

class graph {
    public:
        unordered_map<int, list<int>> adj;
        void addedge(int u, int v) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
}