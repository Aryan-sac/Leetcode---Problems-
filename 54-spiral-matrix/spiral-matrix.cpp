class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size();            // number of rows
        int n = matrix[0].size();         // number of columns
        int srow = 0, erow = m - 1;
        int scol = 0, ecol = n - 1;

        while (srow <= erow && scol <= ecol) {
            // Top row
            for (int j = scol; j <= ecol; j++)
                res.push_back(matrix[srow][j]);

            // Right column
            for (int i = srow + 1; i <= erow; i++)
                res.push_back(matrix[i][ecol]);

            // Bottom row (if not same as top)
            if (srow < erow) {
                for (int j = ecol - 1; j >= scol; j--)
                    res.push_back(matrix[erow][j]);
            }

            // Left column (if not same as right)
            if (scol < ecol) {
                for (int i = erow - 1; i > srow; i--)
                    res.push_back(matrix[i][scol]);
            }

            srow++, erow--;
            scol++, ecol--;
        }

        return res;
    }
};
