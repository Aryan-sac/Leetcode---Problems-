class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        sort(nums.begin(), nums.end());
        int res=0,el=nums[0], count=0;
        for(int i=1; i<nums.size(); i++){
            if(nums[i]-1 == el){
                count++;
                res = max(res, count);
                el=nums[i];
            }
            else if(nums[i]==el)
                continue;
            else if(nums[i]-1 != el){
                count = 0;
                el=nums[i];
            }
        }
        return res+1;
    }
};