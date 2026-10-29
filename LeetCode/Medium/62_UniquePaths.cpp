/**
 * Problem Link : https://leetcode.com/problems/unique-paths/
 * Platform     : LeetCode
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int path(int i, int j, int &m, int &n, vector<vector<int>>& dp){

        if(i>=m || j>=n)
            return 0;

        if((i==m-1 && j==n-1))
        {   
            // dp[i][j]=1; 
            return 1;
        }

        int right = path(i, j+1, m, n, dp);
        int down = path(i+1, j, m, n, dp);

        return right+down;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m, vector<int>(n, 0));
        return path(0,0, m, n, dp);
    }
};
