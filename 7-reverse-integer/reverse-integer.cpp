class Solution {
public:
    int reverse(int x) {
        long long rev = 0;
        int sign = 1;
        long long y = x;
        if (y < 0) {
            sign = -1;
            y = -y;
        }
        while (y != 0) {
            rev = rev * 10 + y % 10;
            if (sign * rev > INT_MAX) return 0;
            if (sign * rev < INT_MIN) return 0;
             y /= 10;
        }
        return (int)(sign * rev);
    }

};