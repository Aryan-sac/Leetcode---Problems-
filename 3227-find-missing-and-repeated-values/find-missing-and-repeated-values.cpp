class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int>ans;
        set<int>s;

        int a, b, n = grid.size();
        int sum = 0;
        for(int i=0; i<n ;i++){
            for(int j=0; j<n; j++){
                sum += grid[i][j];
                if(s.find(grid[i][j]) != s.end()){       // finding repeating element
                    a = grid[i][j];
                    ans.push_back(a);
                }
                s.insert(grid[i][j]);
            }
        }
        int exp_sum =(n*n)*(n*n + 1)/2;  // grid has element from [1 to n*n]  mention in ques
        b = exp_sum - (sum - a);     // subtracting repeating value 'a';
        ans.push_back(b);
        return ans;
    }
};