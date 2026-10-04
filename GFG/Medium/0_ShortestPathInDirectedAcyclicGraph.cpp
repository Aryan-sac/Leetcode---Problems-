/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/shortest-path-in-directed-acyclic-graph/1
 * Platform     : GFG
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void DFS(int node, vector<pair<int, int>> adj[], stack<int>& st, vector<int>& visited){
        visited[node] = 1;
        
        for(int i=0; i<adj[node].size(); i++){
            if(!visited[adj[node][i].first]){
                DFS(adj[node][i].first, adj, st, visited);
            }
        }
        st.push(node);
    }
    
    vector<int> shortestPath(int V, vector<vector<int>>& edges) {
        vector<pair<int, int>> adj[V];

        // Build adjacency list and calculate in-degrees
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
        }

        
        // topological sort (DFS)
        stack<int>st;
        vector<int>visited(V, 0);
        DFS(0, adj, st, visited);


        vector<int>path(V, INT_MAX);
        path[0] = 0;
        while(!st.empty()){
            int el = st.top();
            st.pop();
            
            for(int i=0; i<adj[el].size(); i++){
                int neigh = adj[el][i].first;
                int wt = adj[el][i].second;
                
                path[neigh] = min(path[neigh], (wt + path[el]));
            }
        }
        for(int i=0; i<V; i++){
            if(path[i] == INT_MAX)
                path[i] = -1;
        }

        return path;
    }
};
