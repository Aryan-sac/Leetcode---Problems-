class Solution {
public:
        int KDalgoMin(vector<int>nums){
            int min_sum = nums[0], sum=nums[0];
            for(int i=1; i<nums.size(); i++){
                sum = min(sum+nums[i] , nums[i]);
                min_sum = min(min_sum, sum);
            }
            return min_sum;
        }
        int KDalgoMax(vector<int>nums){
            int max_sum = nums[0], sum=nums[0];
            for(int i=1; i<nums.size(); i++){
                sum = max(sum+nums[i] , nums[i]);
                max_sum = max(max_sum, sum);
            }
            return max_sum;
        }
        int maxSubarraySumCircular(vector<int>& nums) {
            int minSum = KDalgoMin(nums);
            int maxSum = KDalgoMax(nums);
            int total_Sum=0;
            for(int i=0; i<nums.size(); i++){
                total_Sum += nums[i];
            }
            int circular_Sum =  (total_Sum - minSum);
            if(maxSum > 0)
                return max(maxSum, circular_Sum);
            return maxSum;
        }
};