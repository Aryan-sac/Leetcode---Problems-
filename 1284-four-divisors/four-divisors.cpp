class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for (int n : nums) {
            int cnt = 0, sum = 0;
            for (int i = 1; i * i <= n; i++) {
                if (n % i == 0) {
                    cnt++;
                    sum += i;
                    if (i != n / i) {
                        cnt++;
                        sum += n / i;
                    }
                }
                if (cnt > 4) break; // agar 4 se zyada ho gaye to skip
            }
            if (cnt == 4) ans += sum;
        }
        return ans;
    }
};