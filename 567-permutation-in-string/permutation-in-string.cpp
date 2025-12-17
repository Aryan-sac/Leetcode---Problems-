class Solution {
public:
    bool isValid(int freq1[], int freq2[]){
        for(int i=0; i<26; i++){
            if(freq1[i] != freq2[i])
                return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int n1=s1.length(), n2=s2.length();

        int freq1[26] = {0};
        for(auto i: s1)
            freq1[i-'a']++;
        
        for(int i=0; i<n2; i++){
            int winIdx=0, j=i, freq2[26]={0};
            while(winIdx<n1 && j<n2){
                freq2[s2[j]-'a']++;
                j++;
                winIdx++;
            }
            if(isValid(freq1, freq2))
                return true;
        }
        return false;
    }
};