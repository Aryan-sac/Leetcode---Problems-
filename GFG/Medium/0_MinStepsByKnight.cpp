/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/steps-by-knight5927/1
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
    int minStepToReachTarget(vector<int>& src, vector<int>& dest, int n) {
        // Code here

            src[0]--;
            src[1]--;
            dest[0]--;
            dest[1]--;
                
            if(src[0]==dest[0] && src[1]==dest[1])
                return 0;
            
            vector<vector<int>>mat(n, vector<int>(n, 1));
            
            vector<int>rows{2, 2, -2, -2, 1, -1, 1, -1};
            vector<int>cols{1, -1, 1, -1, 2, 2, -2, -2};

            queue<pair<int, int>>q;
            q.push({src[0], src[1]});
            mat[src[0]][src[1]] = 0;

            int steps = 0;
            while(!q.empty()){
                int count = q.size();
                while(count--){
                     int r = q.front().first;
                     int c = q.front().second;

                     q.pop();
                     for(int i=0; i<8; i++){
                         int new_r = r + rows[i];
                         int new_c = c + cols[i];
                         if(new_r==dest[0] && new_c==dest[1])
                            return steps+1;
                         if(valid(new_r, new_c, n) && mat[new_r][new_c]){
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
