// Time  complexity: O(log(n))
// Space complexity: O(1)
class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int digit = x % 10;

            // Check for overflow before multiplying rev by 10
            if (rev > INT_MAX / 10 || rev < INT_MIN / 10) return 0;

            rev = rev * 10 + digit;
            x /= 10;
        }
        return rev;
    }
};
