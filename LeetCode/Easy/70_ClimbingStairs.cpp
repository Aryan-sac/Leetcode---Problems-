/**
 * Problem Link : https://leetcode.com/problems/climbing-stairs/
 * Platform     : LeetCode
 * Difficulty   : Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int fib(int n, vector<int>& dp){

        if(n==1 || n==0)
            return 1;

        if(dp[n] !=  -1)
            return dp[n];
            
        
        dp[n] = fib(n-1, dp) + fib(n-2, dp);
        return dp[n];
    }
    int climbStairs(int n) {
        vector<int>dp(n+1, -1);
        
        return fib(n, dp);
    }
};
