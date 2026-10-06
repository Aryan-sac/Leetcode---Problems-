/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/nth-fibonacci-number1335/1
 * Platform     : GFG
 * Difficulty   : Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    int fib(int n, vector<int>& dp){
        if(dp[n] !=  -1)
            return dp[n];
            
        if(n==1 || n==0)
            return n;
        dp[n] = fib(n-1, dp) + fib(n-2, dp);
        return dp[n];
    }
    
    int nthFibonacci(int n) {
        // code here
        vector<int>dp(n+1, -1);
        
        return fib(n, dp);
    }
};
