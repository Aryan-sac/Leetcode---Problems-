/**
 * Problem Link : https://leetcode.com/problems/unique-paths/
 * Platform     : LeetCode
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int path(int i, int j, int &m, int &n){
        if(i==m-1 && j==n-1)
            return 1;

        if(i>=m || j>=n)
            return 0;

        int right = path(i, j+1, m, n);
        int down = path(i+1, j, m, n);

        return right+down;
    }
    int uniquePaths(int m, int n) {
        return path(0,0, m, n);
    }
};
