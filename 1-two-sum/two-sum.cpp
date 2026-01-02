class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int>m;
        vector<int>res;
        for(int i=0; i<n; i++){
            int first = nums[i];
            int sec = target - first;
            if(m.find(sec) != m.end()){
                res.push_back(i);
                res.push_back(m[sec]);
                break;
            }
            m[first] = i;
        }
        return res;
    }
};