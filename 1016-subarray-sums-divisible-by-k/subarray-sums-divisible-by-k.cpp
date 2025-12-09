class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size(), count=0;
        
        int ps=0;

        unordered_map<int, int>mp;
        for(int j=0; j<n; j++){
            ps += nums[j];
            if(ps%k==0) count++;
            int rem = ((ps%k)+k)%k;
            count += mp[rem];
            mp[rem]++;

        }
        return count;
    }
};