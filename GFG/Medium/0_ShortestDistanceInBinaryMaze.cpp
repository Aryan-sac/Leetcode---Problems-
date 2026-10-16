/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/shortest-path-in-a-binary-maze-1655453161/1
 * Platform     : GFG
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool valid(int r, int c, int n, int m){
        return r>=0 && c>=0 && r<n && c<m; 
    }
    int shortestPath(vector<vector<int>> &mat, vector<int> &src, vector<int> &dest) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        
        if(!mat[src[0]][src[1]] || !mat[dest[0]][dest[1]])
            return -1;
            
        if(src[0]==dest[0] && src[1]==dest[1])
            return 0;
            
        vector<int>rows{1, -1, 0, 0};
        vector<int>cols{0, 0, -1, 1};
        
        queue<pair<int, int>>q;
        q.push({src[0], src[1]});
        
        int steps = 0;
        while(!q.empty()){
            int count = q.size();
            while(count--){
                 int r = q.front().first;
                 int c = q.front().second;
                 
                 q.pop();
                 for(int i=0; i<4; i++){
                     int new_r = r + rows[i];
                     int new_c = c + cols[i];
                     if(new_r==dest[0] && new_c==dest[1])
                        return steps+1;
                     if(valid(new_r, new_c, n, m) && mat[new_r][new_c]){
                        mat[new_r][new_c] = 0;
                        q.push({new_r, new_c});
                     }
                 }
             }
            steps++;
        }
        return -1;
    }
};

