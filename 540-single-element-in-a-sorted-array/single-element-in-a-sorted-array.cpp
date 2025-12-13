class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int st=0, end=n-1;
        if(n==1) return nums[0];
        while(st<=end){
            int mid = st + (end-st)/2;
            
            // Handle Corner element (if mid=0 then nums[mid-1] not exist) similarly (if mid=n-1 then nums[mid+1] not exist)
            if(mid==0 && nums[0]!=nums[1])
                return nums[0];
            else if(mid==n-1 && nums[n-1]!=nums[n-2])
                return nums[n-1];

            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1])        // Answer
                return nums[mid];
            
            if(mid%2==0)    // both side even number of values  ( {in left and right Subarray} not including mid)
            {
                // search in Left
                if(nums[mid] == nums[mid-1])
                    end = mid-1;
                // search in Right
                else
                    st = mid+1;
            }
            else{           // both side odd values (not including mid)
                // search in Left
                if(nums[mid] == nums[mid-1])
                    st = mid+1;
                // search in Right
                else
                    end = mid-1;
            }
        }
        return -1;
    }
};