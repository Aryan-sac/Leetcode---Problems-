class Solution {
public:
    bool isPalindrome(int x) {
        long rev = 0, original = x;
        while(x>0){
            int rem = x%10;
            rev = rev*10 + rem;
            x/=10;
        }
        if(original == rev) return true;
        return false;

    }
};