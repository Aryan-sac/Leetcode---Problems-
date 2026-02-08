class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int,int> freq;  // remainder -> count
        int count = 0, k=60;
        for (int t : time) {
            int r = t % k;
            int complement = (k - r) % k;
            if (freq.find(complement) != freq.end()) {
                count += freq[complement];
            }
            freq[r]++;
        }
        return count;
    }
};