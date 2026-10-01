/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1
 * Platform     : GFG
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool prerequisiteTasks(int n, vector<vector<int>>& pre) {
        // code here
        queue<int>q;
        vector<int>InDeg(n, 0);
        vector<vector<int>>adj(n);
        for(int i=0; i<pre.size(); i++){
            adj[pre[i][1]].push_back(pre[i][0]);
            InDeg[pre[i][0]]++;
        }
        
        
        for(int i=0; i<n ;i++)
        {
            if(!InDeg[i])
                q.push(i);
        }
        int count = 0;
        while(!q.empty()){
            int el = q.front();
            q.pop();
            count++;
            for(int i=0; i<adj[el].size(); i++){
                InDeg[adj[el][i]]--;
                if(!InDeg[adj[el][i]])
                    q.push(adj[el][i]);
            }
        }
        return count==n;
    }
};
