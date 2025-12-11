class Solution {
public:
    int search(vector<int>& nums, int target) {
       int st=0, end=nums.size()-1;
       while(st<=end){
            int mid = st + (end-st)/2;
            // Found then return idx
            if(nums[mid] == target)
                return mid;
            
            // check if Left half is sorted ?
            if(nums[st] <= nums[mid]){
                // ckeck target is exist int this range or not
                if(nums[st] <= target && target <= nums[mid])   // exist
                    end = mid-1;
                else        // not exist
                    st = mid+1;
            }
            //  check if Right half is sorted ?
            else{
                // check target is exist in this range or not 
                if(nums[mid] <= target && target <= nums[end])  // exist
                    st = mid+1;
                else        // not exist
                    end = mid-1;

            }
       }
       return -1;
    }
};