class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            vector<bool> row(n + 1, false);
            vector<bool> col(n + 1, false);

            for (int j = 0; j < n; j++) {
                int r = matrix[i][j], c = matrix[j][i];
                
                if (r < 1 || r > n || row[r]) return false;
                if (c < 1 || c > n || col[c]) return false;
                
                row[r] = true;
                col[c] = true;
            }
        }
        return true;
    }
};