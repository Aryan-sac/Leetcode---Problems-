class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        int iniColor = image[sr][sc]; // 1. Save the original color
        if (iniColor == color) return image;

        queue<pair<int, int>>q;
        image[sr][sc] = color;
        q.push({sr, sc});
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            // up
            if(row > 0 && image[row-1][col] == iniColor){ // 2. Check iniColor instead of 1
                q.push({row-1, col});
                image[row-1][col] = color;
            }
            // bottom
            if(row < n-1 && image[row+1][col] == iniColor) { // Check iniColor instead of 1
                q.push({row+1, col});
                image[row+1][col] = color;
            }
            // left
            if(col > 0 && image[row][col-1] == iniColor){ // Check iniColor instead of 1
                q.push({row, col-1});
                image[row][col-1] = color;
            }
            // right
            if(col < m-1 && image[row][col+1] == iniColor){ // Check iniColor instead of 1
                q.push({row, col+1});
                image[row][col+1] = color;
            }        
        }
        return image;
    }
};