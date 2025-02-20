// Time  complexity: O(log(n))
// Space complexity: O(1)
class Solution {
  public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x != 0 && x % 10 == 0)
            return false; // Numbers ending in 0 (except 0 itself) are not
                          // palindromes

        long long reversed = 0;
        int original = x;

        while (x > 0) {
            int digit = x % 10;
            reversed = reversed * 10 + digit;
            x /= 10;
        }

        return original == reversed;
    }
};
