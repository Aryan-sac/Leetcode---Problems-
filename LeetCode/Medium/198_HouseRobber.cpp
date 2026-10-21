/**
 * Problem Link : https://leetcode.com/problems/house-robber/
 * Platform     : LeetCode
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& cost){
        int n = cost.size();
        if (n == 0) return 0;
        if (n == 1) return cost[0];
        vector<int>arr(n);
        arr[0] = cost[0];
        arr[1] = max(cost[0], cost[1]);
        for(int i=2; i<n; i++){
            arr[i] = max(arr[i-1], arr[i-2] + cost[i]);
        }
        return arr[n-1];
    }
};
