class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[0];
        do{
            slow = nums[slow];              // +1
            fast = nums[nums[fast]];        // +2
        }
        while(slow != fast);
        slow = nums[0];
        while(slow != fast){
            slow = nums[slow];              // +1 from starting of the array
            fast = nums[fast];              // +1 from current position of the fast
        }
        return fast;
    }
};