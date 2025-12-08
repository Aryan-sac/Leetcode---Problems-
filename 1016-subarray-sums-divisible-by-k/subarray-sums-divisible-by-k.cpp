class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size(), count=0;
        vector<int>ps(n, 0);
        
        ps[0] =  nums[0];
        for(int i=1; i<n; i++){
            ps[i] = ps[i-1] + nums[i];
        }

        unordered_map<int, int>mp;
        for(int j=0; j<n; j++){
            if(ps[j]%k==0) count++;
            int rem = ((ps[j] % k) + k) % k; // normalize remainder
            count += mp[rem];
            mp[rem]++;

        }
        return count;
    }
};