/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/circle-of-strings4530/1
 * Platform     : GFG
 * Difficulty   : Hard
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  void dfs(int node, vector<int>adj[], vector<bool>& visited){
      visited[node] = true;
      
      for(int i=0; i<adj[node].size(); i++){
          int x = adj[node][i];
          if(!visited[x])
            dfs(x, adj, visited);
      }
  }
    bool isCircle(vector<string> &arr) {
        // code here
        vector<int>adj[26];
        vector<int>Indeg(26, 0);
        vector<int>Outdeg(26, 0);
        
        for(int i=0; i<arr.size(); i++){
            int u = arr[i][0]-'a';
            int v = arr[i][arr[i].size()-1]-'a';
            adj[u].push_back(v);
            
            Indeg[u]++;
            Outdeg[v]++;
        }
        
        for(int i=0; i<26; i++){
            if(Indeg[i] != Outdeg[i])
                return false;
        }
        
        vector<bool>visited(26, 0);
        dfs(arr[0][0]-'a', adj, visited);
        
        for(int i=0; i<26; i++){
            if(Indeg[i] && !visited[i])
                return false;
        }
        return true;
    }
};
