/**
 * Problem Link : https://leetcode.com/problems/n-th-tribonacci-number/
 * Platform     : LeetCode
 * Difficulty   : Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trib(int n, vector<int>& dp){
        if(dp[n] !=  -1)
            return dp[n];
            
        if(n==0)
            return n;
        if(n==1 || n==2)
            return 1;

        dp[n] = trib(n-1, dp) + trib(n-2, dp) + trib(n-3, dp);
        return dp[n];
    }

    int tribonacci(int n) {
        vector<int>dp(n+1, -1);
        return trib(n, dp);
    }
};
