class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> vec(m, vector<int>(n));

        int x = 0;
        if(original.size() == m*n)
        {
            for(int i=0 ;i<m; i++){
                for(int j=0 ;j<n; j++){
                    vec[i][j] = original[x++];
                }
            }
            return vec;
        }
        return {};

    }
};