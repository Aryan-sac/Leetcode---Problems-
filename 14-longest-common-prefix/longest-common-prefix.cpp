class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        // iterate over characters of the first string
        for (int i = 0; i < strs[0].size(); i++) {

            char c = strs[0][i];  // candidate character

            // check this character against all other strings
            
            for (int j = 1; j < strs.size(); j++) {
                // mismatch OR string too short
                if (i >= strs[j].size() || strs[j][i] != c) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0]; // if no mismatch, whole first string is prefix
    }
};