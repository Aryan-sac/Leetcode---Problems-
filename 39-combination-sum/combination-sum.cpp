class Solution {
public:
    vector<vector<int>>res;
    void helper(vector<int>&arr, int target, int idx, vector<int>ans){
        if(target<0)
            return;
        if(idx==arr.size())
        {
            if(target == 0){
                res.push_back(ans);
            }
            return;
        }
        ans.push_back(arr[idx]);
        helper(arr, target-arr[idx], idx, ans);
        ans.pop_back();
        helper(arr, target, idx+1, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>ans;
        helper(candidates, target, 0, ans);
        return res;
    }
};