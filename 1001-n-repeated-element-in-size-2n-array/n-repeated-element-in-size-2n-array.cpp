class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int ans;
        unordered_map<int,int>mp;
        for(int i=0; i<nums.size(); i++){
            if(mp.find(nums[i])!=mp.end())
            {
                ans = nums[i];
                break;
            }
            mp[nums[i]]++;
        }
        return ans;
    }
};