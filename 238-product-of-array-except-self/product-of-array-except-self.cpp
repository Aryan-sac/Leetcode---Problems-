class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int  n = nums.size(),product =1;
        vector<int>ans(n, 1);
        int right_product=1, left_product=1, x=0;

        for(int i =1; i<n ;i++){
            left_product =  left_product * nums[i-1];
            ans[i] = left_product;
        }

        for(int j =n-2; j>=0 ;j--){
            right_product = right_product * nums[j+1];
            ans[j] *= right_product;
        }
        return ans;
    }
};