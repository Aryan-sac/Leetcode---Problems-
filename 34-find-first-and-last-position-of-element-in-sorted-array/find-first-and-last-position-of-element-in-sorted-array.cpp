class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>res(2,-1);
        int st=0, end=n-1;
        while(st <= end){
            int mid = st + (end-st)/2;
            if(nums[mid] == target){
                // finding first idx
                int i=mid;
                while(i>0 && nums[i] == nums[i-1])
                i--;
                res[0]=i;

                // finding last idx
                i=mid;
                while(i<n-1 && nums[i] == nums[i+1])
                i++;
                res[1]=i;

                return res;
            }
            else if(nums[mid] < target)
                st = mid+1;
            else
                end=mid-1;
        }
        return res;
    }
};