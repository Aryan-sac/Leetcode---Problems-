class Solution {
public:

    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(matrix[i][j] == 0) {
                    // mark row i
                    for(int a=0; a<n; a++) {
                        if(matrix[i][a] != 0) matrix[i][a] = -100000;
                    }
                    // mark column j
                    for(int a=0; a<m; a++) {
                        if(matrix[a][j] != 0) matrix[a][j] = -100000;
                    }
                }
            }
        }
        
        // convert markers to zero
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(matrix[i][j] == -100000) matrix[i][j] = 0;
            }
        }
    }

};