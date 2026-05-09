class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int el=INT_MAX;
        for(int i=0; i<n; i++){
           el =  min(el, nums[i]);
        }
        return el;
    }
};