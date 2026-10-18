/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/euler-circuit-and-path/1
 * Platform     : GFG
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& visited){
        visited[node] = 1;
        
        for(int i=0; i<adj[node].size(); i++){
            if(!visited[adj[node][i]])
                dfs(adj[node][i], adj, visited);
        }
    }
    int isEulerCircuit(int V, vector<vector<int>>& adj) {
        // code here
        vector<int>visited(V, 0);
        vector<int>deg(V, 0);
        int odd_deg=0;
        
        for(int i=0; i<V; i++){
            deg[i] = adj[i].size();
            
            if(deg[i]%2)
                odd_deg++;
        }
        
        if(odd_deg!=2 && odd_deg!=0)
            return 0;
            
        for(int i=0; i<V; i++){
            if(deg[i])  // Non zero deg node (start dfs)
            {
                dfs(i, adj, visited);
                break;
            }
        }
        
        for(int i=0; i<V; i++){
            if(deg[i] && !visited[i])
                return 0;
        }
        
        if(odd_deg == 0)
            return 2;
        
        if(odd_deg == 2)
            return 1;
    }
};
