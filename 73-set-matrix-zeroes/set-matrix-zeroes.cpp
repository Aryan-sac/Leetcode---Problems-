class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>>temp = matrix;
        for(int i=0; i<matrix.size(); i++)
        {
            for(int j=0; j<matrix[0].size(); j++){
                if(matrix[i][j]==0)
                {
                    // for rows
                    for(int a=0; a<matrix[0].size(); a++){
                        temp[i][a]=0;
                    }
                    // for columns
                    for(int a=0; a<matrix.size(); a++){
                        temp[a][j]=0;
                    }
                }
            }
        }
        matrix = temp;
    }
};