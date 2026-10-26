/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/bridge-edge-in-graph/1
 * Platform     : GFG
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, int c, int d) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if ((node == c && it == d) || (node == d && it == c)) continue;
            if (!vis[it]) {
                dfs(it, adj, vis, c, d);
            }
        }
    }

    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        vector<vector<int>> adj(V);
        for (auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> vis(V, 0);
        dfs(c, adj, vis, c, d);

        return !vis[d];
    }
};
