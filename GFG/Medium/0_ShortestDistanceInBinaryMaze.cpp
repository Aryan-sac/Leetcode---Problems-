/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/shortest-path-in-a-binary-maze-1655453161/1
 * Platform     : GFG
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPath(vector<vector<int>> &mat, vector<int> &src, vector<int> &dest) {
        int n = mat.size();
        int m = mat[0].size();

        if (mat[src[0]][src[1]] == 0 || mat[dest[0]][dest[1]] == 0) {
            return -1;
        }

        if (src[0] == dest[0] && src[1] == dest[1]) {
            return 0;
        }

        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> dist(n, vector<int>(m, 1e9));

        q.push({0, {src[0], src[1]}});
        dist[src[0]][src[1]] = 0;

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;

            if (r == dest[0] && c == dest[1]) {
                return dis;
            }

            for (int i = 0; i < 4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && 
                    mat[nrow][ncol] == 1 && dis + 1 < dist[nrow][ncol]) {

                    dist[nrow][ncol] = dis + 1;
                    q.push({dis + 1, {nrow, ncol}});
                }
            }
        }

        return -1;
    }
};
