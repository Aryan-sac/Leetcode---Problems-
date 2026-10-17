/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/find-whether-path-exist5238/1
 * Platform     : GFG
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool valid(int r, int c, int n){
        return r>=0 && c>=0 && r<n && c<n;
    }
    bool isPathPossible(vector<vector<int>>& mat) {
        // code here
        queue<pair<int, int>>q;
        int n = mat.size();
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++)
            {
                if(mat[i][j] == 1)
                {
                   q.push({i, j});
                   break;
                }
            }
        }
        if(q.empty())
            return false;
        
        int rows[4] = {-1, 1, 0, 0};
        int cols[4] = {0, 0, -1, 1};
        
        while(!q.empty()){
            int count = q.size();
            while(count--){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                
                for(int i=0; i<4; i++){
                    int new_r = row + rows[i];
                    int new_c = col + cols[i];
                    if(valid(new_r, new_c, n) && mat[new_r][new_c] == 2)
                        return true;
                        
                    if(valid(new_r, new_c, n) && mat[new_r][new_c]==3)
                    {
                        mat[new_r][new_c] = 0;
                        q.push({new_r, new_c});
                    }
                }
            }
        }
        return false;
    }
};
