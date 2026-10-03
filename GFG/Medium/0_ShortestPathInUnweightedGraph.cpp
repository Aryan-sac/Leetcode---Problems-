/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1
 * Platform     : GFG
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
        // code here
        vector<int>adj[V];
        for(int i=0; i<edges.size(); i++){
            int v = edges[i][0];
            int u = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int>path(V, -1);
        vector<int>visited(V, 0);
        
        path[src] = 0;
        queue<int>q;
        q.push(src);
        
        while(!q.empty()){
            int el = q.front();
            q.pop();
            for(int i=0; i<adj[el].size(); i++){
                if(!visited[adj[el][i]]){
                    visited[adj[el][i]] = 1;
                    q.push(adj[el][i]);
                    
                    path[adj[el][i]] = path[el] + 1;
                }
            }
        }
        
        return path[dest];
        
    }
};

