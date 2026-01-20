class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int>res;
        for(int i=0; i<nums.size(); i++){
            int ans = 0, found=0;
            while(ans<=nums[i])
            {
                if((ans | (ans + 1)) == nums[i])
                {
                    res.push_back(ans);
                    found = 1;
                    break;
                }
                ans++;
            }
            if(found == 0)
                res.push_back(-1);
        }
        return res;
    }
};