class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size(),res=INT_MIN;
        int prefix=1, suffix=1;
        for(int i=0; i<n; i++){
            if(prefix == 0) prefix=1;
            if(suffix == 0) suffix=1;
            prefix *= nums[i];
            suffix *= nums[n-i-1];
            res = max(res, max(prefix, suffix));
        }
        return res;
    }
};