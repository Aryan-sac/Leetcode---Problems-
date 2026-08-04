class Solution {
public:
    string res = "";
    int  maxlen = 0;
    int pal(string s, int l, int r){
        while(l>=0 && r<s.length() && s[l] == s[r]){
            l--;
            r++;
        }
        //Length = (r - 1) - (l + 1) + 1 = r - l - 1;
        return r - l - 1;
    }
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int start = 0;
        int n = s.size();

        for(int i=0; i<n ; i++){
            // 1. Check odd-length palindromes (center at i)
            int len1 = pal(s, i, i);
            if (len1 > maxlen) {
                maxlen = len1;
                // Calculate start index for odd-length palindrome centered at i
                int start = i - (len1 - 1) / 2;
                res = s.substr(start, maxlen);
            }

            // 2. Check even-length palindromes (center between i and i + 1)
            int len2 = pal(s, i, i + 1);
            if (len2 > maxlen) {
                maxlen = len2;
                // Calculate start index for even-length palindrome centered between i and i + 1
                int start = i - (len2 / 2 - 1);
                res = s.substr(start, maxlen);
            }
        }
        return res;
    }
};