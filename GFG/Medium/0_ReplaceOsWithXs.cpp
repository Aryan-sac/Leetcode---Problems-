/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/replace-os-with-xs0052/1
 * Platform     : GFG
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int n, m;
    void check(int n, int m, queue<pair<int,int>>& q, vector<vector<char>>& grid){
            while(!q.empty()){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                // up
                if(row > 0 && grid[row-1][col] == 'O'){
                    q.push({row-1, col});
                    grid[row-1][col] = '1';
                }
                // bottom
                if(row < n-1 && grid[row+1][col] == 'O'){
                    q.push({row+1, col});
                    grid[row+1][col] = '1';
                }
                // left
                if(col > 0 && grid[row][col-1] == 'O'){
                    q.push({row, col-1});
                    grid[row][col-1] = '1';
                }
                // right
                if(col < m-1 && grid[row][col+1] == 'O'){
                    q.push({row, col+1});
                    grid[row][col+1] = '1';
                }
            }
        }
    void fill(vector<vector<char>>& grid) {
        // Code here
        queue<pair<int, int>>q;
        
        n = grid.size();
        m = grid[0].size();
        
        for(int i = 0; i < m; i++){
                if(grid[0][i] == 'O'){
                    q.push({0, i});
                    grid[0][i] = '1';
                }
                if(grid[n-1][i] == 'O'){
                    q.push({n-1, i});
                    grid[n-1][i] = '1';
                }
            }

            // Left and Right columns
            for(int i = 0; i < n; i++){
                if(grid[i][0] == 'O'){
                    q.push({i, 0});
                    grid[i][0] = '1';
                }
                if(grid[i][m-1] == 'O'){
                    q.push({i, m-1});
                    grid[i][m-1] = '1';
                }
            }
            
            check(n, m, q, grid);
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]=='O')
                    grid[i][j] = 'X';
                    
                else if(grid[i][j]=='1')
                    grid[i][j] = 'O';
            }
        }
    }
};
