/**
 * Problem Link : https://leetcode.com/problems/is-graph-bipartite/
 * Platform     : LeetCode
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int>visited(V, 0);
        vector<int>color(V, -1);

        vector<vector<int>>adj(V);
        for(int i=0; i<V; i++){
            for(int j=0; j<graph[i].size(); j++){
                adj[i].push_back(graph[i][j]);
            }
        }

        vector<int>colour(V, -1);
        queue<int>q;
        for(int i=0; i<V; i++){
            if(colour[i] != -1) continue;
            q.push(i);
            colour[i] = 1;

            while(!q.empty()){
                
                int el = q.front();
                q.pop();
                
                for(int i=0; i<adj[el].size(); i++){
                    if(colour[adj[el][i]] == -1)
                    {
                        colour[adj[el][i]] = (colour[el] + 1)%2;
                        q.push(adj[el][i]);
                    }
                    
                    else if(colour[adj[el][i]] == colour[el])
                        return false;
                }
            }
        }
        return true;
    }
};
