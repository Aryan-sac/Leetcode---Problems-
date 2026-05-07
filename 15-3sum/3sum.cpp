class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        set<vector<int>> unique;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++){
            int j=i+1, k=n-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k]; 
                if(sum == 0)
                {
                    unique.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }
                else if(sum > 0)
                    k--;
                else
                    j++;
            }
        }
        vector<vector<int>>res(unique.begin(), unique.end());
        return res;
    }
};