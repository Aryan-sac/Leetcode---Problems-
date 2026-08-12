class Solution {
public:
    vector<vector<int>>res;

    void helper(vector<int>& arr, int target, int idx, vector<int>ans){

        if(target == 0){
            res.push_back(ans);
            return;}

        if(idx == arr.size() || target<0)
            return;

        // 1. INCLUDE arr[idx]
        ans.push_back(arr[idx]);
        helper(arr, target - arr[idx], idx + 1, ans);

        ans.pop_back(); // Backtrack

        // 2. EXCLUDE arr[idx] (Skip all duplicate occurrences of arr[idx] immediately)
        while (idx + 1 < arr.size() && arr[idx] == arr[idx + 1]) {
            idx++;
        }
        helper(arr, target, idx + 1, ans);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int>ans;
        helper(candidates, target, 0, ans);
        return res;
    }
};