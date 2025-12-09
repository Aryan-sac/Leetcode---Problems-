class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size(), count=0;
        
        int ps=0;
        unordered_map<int, int>mp;
        mp[0] = 1;

        for(int j=0; j<n; j++){
            ps += nums[j];

            int rem = ps%k;

            if(rem<0) rem = rem+k;    // handle negative index

            count += mp[rem];
            mp[rem]++;

        }
        return count;
    }
};