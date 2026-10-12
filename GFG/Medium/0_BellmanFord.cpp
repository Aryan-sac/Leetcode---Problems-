/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1
 * Platform     : GFG
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int>dist(V, 1e8);
        
        dist[src] = 0;
        int e = edges.size();
        
        for(int i=0; i<V-1; i++){
            
            int change = 0;
            // relax all edges
            for(int j=0; j<e; j++){
                int u = edges[j][0];
                int v = edges[j][1];
                int wt = edges[j][2];
                
                // no change if dist[u] is INFINITE
                if(dist[u] == 1e8)
                continue;
                
                if(dist[u]+wt < dist[v])
                {
                    dist[v] = dist[u]+wt;
                    change = 1;
                }
            }
            if(change == 0)
                return dist;
        }
        
        // relax one more time
        for(int j=0; j<e; j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];
            
            if(dist[u]+wt < dist[v])
            {
                // cycle detected
                vector<int>ans;
                ans.push_back(-1);
                return ans;
            }
        }
        return dist;
    }
};

