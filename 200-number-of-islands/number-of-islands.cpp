class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        queue<pair<int, int>>q;
        int islands = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1')
                {
                    islands++;
                    q.push({i, j});
                    grid[i][j]='0';
                    while(!q.empty()){
                        int row = q.front().first;
                        int col = q.front().second;
                        q.pop();
                        // up
                        if(row>0 && grid[row-1][col]=='1'){
                            q.push({row-1, col});
                            grid[row-1][col]='0';
                        }
                        // bottom
                        if(row<n-1 && grid[row+1][col]=='1')
                        {
                            q.push({row+1, col});
                            grid[row+1][col]='0';
                        }
                        // left
                        if(col>0 && grid[row][col-1]=='1'){
                            q.push({row, col-1});
                            grid[row][col-1]='0';
                        }
                        // right
                        if(col<m-1 && grid[row][col+1]=='1'){
                            q.push({row, col+1});
                            grid[row][col+1]='0';
                        }
                    }
                }
            }
        }
        return islands;
    }
};