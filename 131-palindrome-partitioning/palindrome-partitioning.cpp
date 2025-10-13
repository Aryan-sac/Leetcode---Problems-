class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> partitions;
        vector<vector<string>> res;
        AllPossibleResult(s, res, partitions);
        return res;
    }

    void AllPossibleResult(string s, vector<vector<string>>& res, vector<string>& partitions) {
        if (s.length() == 0) {
            res.push_back(partitions);
            return;
        }

        for (int i = 0; i < s.length(); i++) {
            string left_part = s.substr(0, i+1);
            if (isPalindrome(left_part)) {
                partitions.push_back(left_part);
                AllPossibleResult(s.substr(i+1), res, partitions);
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