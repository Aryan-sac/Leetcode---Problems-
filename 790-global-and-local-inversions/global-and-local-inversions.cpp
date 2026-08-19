class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int max_val = -1;
        for (int i = 0; i < (int)nums.size() - 2; i++) {
            max_val = max(max_val, nums[i]);
            if (max_val > nums[i + 2]) {
                return false;
            }
        }
        return true;
    }
};