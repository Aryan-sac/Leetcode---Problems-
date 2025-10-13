class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> partitions;
        vector<vector<string>> res;
        AllPossibleResult(s, res, partitions, 0);
        return res;
    }

    void AllPossibleResult(string s, vector<vector<string>>& res, vector<string>& partitions, int idx) {
        if (idx == s.length()) {
            res.push_back(partitions);
            return;
        }

        for (int i = idx; i < s.length(); i++) {
            string left_part = s.substr(idx, i - idx + 1); // fix: substr from idx, not 0
            if (isPalindrome(left_part)) {
                partitions.push_back(left_part);
                AllPossibleResult(s, res, partitions, i + 1);
                partitions.pop_back();
            }
        }
    }

    bool isPalindrome(string str) {
        int r = str.length() - 1, l = 0;
        while (l < r) {
            if (str[l] != str[r]) return false;
            l++; r--;
        }
        return true;
    }
};