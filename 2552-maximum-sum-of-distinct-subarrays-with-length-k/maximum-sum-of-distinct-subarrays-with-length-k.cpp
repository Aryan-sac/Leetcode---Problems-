class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0;
        unordered_map<int, int> mp;
        long long val = 0;

        // Sliding window
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
            val += nums[i];

            if(i >= k) {
                mp[nums[i-k]]--;
                val -= nums[i-k];
                if(mp[nums[i-k]] == 0) mp.erase(nums[i-k]);
            }

            // Only update answer if window size == k and all distinct
            if(i >= k-1 && mp.size() == k) {
                ans = max(ans, val);
            }
        }
        return ans;
    }

};