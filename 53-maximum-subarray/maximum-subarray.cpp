class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int highest = INT_MIN,sum, n=nums.size();
        for(int i=0; i<n; i++){
            sum += nums[i];
            highest = max(highest, sum);

            if(sum < 0)
            sum = 0;
        }
        return highest;
    }
};