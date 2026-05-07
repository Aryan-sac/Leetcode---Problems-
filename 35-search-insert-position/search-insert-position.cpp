class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int st = 0, end = nums.size() - 1;
        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (nums[mid] == target) 
                return mid;              // exact match
            else if (nums[mid] < target) 
                st = mid + 1;            // move right
            else 
                end = mid - 1;           // move left
        }
        return st;   // insertion position
    }

};