class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int n = nums.size();
        int count = 0;

        vector<int> PS(n, 0);
        PS[0] = nums[0];
        for (int i = 1; i < n; i++)
            PS[i] = PS[i - 1] + nums[i];

        for(int j=0; j<n; j++){
            if(PS[j] == k)  count++;

            int val = PS[j] - k;

            if(map.find(val) != map.end())
                count += map[val];

            if(map.find(PS[j]) == map.end())
                map[PS[j]] = 0;

            map[PS[j]]++;
        }

        return count;
    }
};
