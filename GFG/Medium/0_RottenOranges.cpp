/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1
 * Platform     : GFG
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int orangesRot(vector<vector<int>>& mat) {
        // code here
        queue<pair<int, int>>q;
        int n = mat.size();
        int m = mat[0].size();

        int flag = 0; // Fresh Oranges are Present if not then return 0??

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++)
            {
                if(mat[i][j] == 2)
                    q.push({i, j});

                else if(mat[i][j]==1)
                    flag = 1;   // Fresh Oranges Present to rotten them by rotten Oranges
            }
        }
        if(flag == 0)
            return 0;

        int count = 0;
        while(!q.empty()){
            count ++;

            int rotten = q.size();
            while(rotten--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                // UP
                if(i>0 && mat[i-1][j]==1)
                {
                    mat[i-1][j] = 2;
                    q.push({i-1, j});
                }

                // Down
                if(i<n-1 && mat[i+1][j]==1)
                {
                    mat[i+1][j] = 2;
                    q.push({i+1, j});
                }

                // Left
                if(j>0 && mat[i][j-1]==1)
                {
                    mat[i][j-1] = 2;
                    q.push({i, j-1});
                }

                // Right
                if(j<m-1 && mat[i][j+1]==1)
                {
                    mat[i][j+1] = 2;
                    q.push({i, j+1});
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]==1)
                    return -1;
            }
        }
        return count-1;
    }
};
