class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<char, int> freq;
            for (int j = i; j < n; j++) {
                freq[s[j]]++;

                // check balance
                int common = 0;
                bool balanced = true;
                for (auto &p : freq) {
                    if (common == 0) common = p.second;
                    else if (p.second != common) {
                        balanced = false;
                        break;
                    }
                }

                if (balanced) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }
        return maxLen;
    }

};