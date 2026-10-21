/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1
 * Platform     : GFG
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int, int>>> adj(V);
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt}); // Since it's an undirected graph
        }
        
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;
        
        vector<bool>IsMst(V, 0);
        vector<int>parent(V);
        int cost = 0;
        
        pq.push({0, {0, -1}});
        while(!pq.empty()){
            int wt = pq.top().first;
            int node = pq.top().second.first;
            int par = pq.top().second.second;
            pq.pop();
            
            if(!IsMst[node]){
                IsMst[node] = 1;
                cost += wt;
                parent[node] = par;
                
                for(int i=0; i<adj[node].size(); i++){
                    int adjNode = adj[node][i].first;
                    int edgeWeight = adj[node][i].second;
                    if(!IsMst[adjNode])
                    {   
                        pq.push({edgeWeight, {adjNode, node}});
                    }
                }
            }
        }
        return cost;
    }
};
