class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string result= "";

        // Reverse Whole String         --->  eulb si yks eht
        reverse(s.begin(),s.end());

        // Reverse Each word and store in result string
        for(int i=0 ; i<n; i++){
            string word = "";
            while((i<n) && (s[i] != ' ')){
                word += s[i];
                i++;
            }
            reverse(word.begin(), word.end());
            if(word.length() > 0)
            {
                if(result == "")
                    result += word;
                else
                    result += " " + word;
            }
        }
        return result;
    }
};