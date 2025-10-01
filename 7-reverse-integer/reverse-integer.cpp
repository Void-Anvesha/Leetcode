class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int mod = x % 10;
            // Check for overflow *before* updating rev
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && mod > 7)) return 0;
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && mod < -8)) return 0;
            rev = rev * 10 + mod;
            x /= 10;
        }
        return rev;
    }
};
