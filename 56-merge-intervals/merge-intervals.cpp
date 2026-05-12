class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        vector<vector<int>> res;
        int n=arr.size();
        sort(arr.begin(), arr.end());
        for(int i=0;i<n; i++){
            int st = arr[i][0];
            int end = arr[i][1];

            if(!res.empty() && end<=res.back()[1])
                continue;
            
            for(int j=i+1; j<n; j++){
                if(arr[j][0] <= end)
                    end = max(end, arr[j][1]);
                else
                    break;
            }
            res.push_back({st, end});            
        }
        return res;
    }
};