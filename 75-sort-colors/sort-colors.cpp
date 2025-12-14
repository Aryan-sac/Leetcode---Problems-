class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0, mid=0, high=nums.size()-1;

        while(mid<=high){
            // if mid idx point to 0  -->  swap with low/0's place
            if(nums[mid] == 0){
                swap(nums[mid], nums[low]);
                mid++, low++;
            }
            // if mid idx point to 1  -->  already sorted 
            else if(nums[mid] == 1){
                mid++;
            }
            // if mid idx point to 2  -->  swap with higher/2's place
            else{
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};