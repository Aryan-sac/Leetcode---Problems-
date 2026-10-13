/**
 * Problem Link : https://leetcode.com/problems/min-cost-climbing-stairs/
 * Platform     : LeetCode
 * Difficulty   : Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int solve(vector<int>& cost, int n, vector<int>& dp) {
        if (n <= 1) return 0;
        if(dp[n] != 1e8)
            return dp[n];

        int option1 = solve(cost, n - 1, dp) + cost[n - 1];
        int option2 = solve(cost, n - 2, dp) + cost[n - 2];
        
        dp[n] = min(option1, option2);

        return dp[n];
    }

public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(cost.size()+1, 1e8);
        int n = cost.size();
        return solve(cost, n, dp);
    }
};
