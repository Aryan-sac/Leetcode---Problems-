/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/course-schedule/1
 * Platform     : GFG
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> findOrder(int n, vector<vector<int>> &pre) {
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
                vector<int>ans;
                while(!q.empty()){
                    int el = q.front();
                    q.pop();
                    ans.push_back(el);
                    for(int i=0; i<adj[el].size(); i++){
                        InDeg[adj[el][i]]--;
                        if(!InDeg[adj[el][i]])
                            q.push(adj[el][i]);
                    }
                }
                // Check if all tasks can be completed (i.e., no cycle)
                        if (ans.size() != n) {
                            return {};
                        }

                        return ans;
    }
};
