/**
 * Problem Link : https://leetcode.com/problems/surrounded-regions/
 * Platform     : LeetCode
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void check(int n, int m, queue<pair<int, int>>& q, vector<vector<char>>& board){
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;

            q.pop();

            // Top check
            if(row>0 && board[row-1][col]=='O')
            {
                q.push({row-1, col});
                board[row-1][col] = '$';
            }

            // Bottom check
            if(row<n-1 && board[row+1][col]=='O'){
                q.push({row+1, col});
                board[row+1][col] = '$';
            }

            // Left check
            if(col>0 && board[row][col-1]=='O')
            {
                q.push({row, col-1});
                board[row][col-1] = '$';
            }

            // Right check
            if(col<m-1 && board[row][col+1]=='O')
            {
                q.push({row, col+1});
                board[row][col+1] = '$';
            }

        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        queue<pair<int, int>>q;

        // insert Top and Bottom row O's
        for(int i=0; i<m; i++){
            if(board[0][i]=='O')
            {
                q.push({0, i});
                board[0][i] = '$';
            }
            
            if(board[n-1][i]=='O')
            {
                q.push({n-1, i});
                board[n-1][i] = '$';
            }

        }

        //  insert Left and Right column O's
        for(int i=0; i<n; i++){
            if(board[i][0]=='O')
            {
                q.push({i, 0});
                board[i][0] = '$';
            }
            
            if(board[i][m-1]=='O')
            {
                q.push({i, m-1});
                board[i][m-1] = '$';
            }
        }

        check(n, m, q, board);

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                
                else if(board[i][j] == '$')
                    board[i][j] = 'O';
            }
        }

    }
};
