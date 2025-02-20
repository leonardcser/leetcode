// Time  complexity: O(n^2)
// Space complexity: O(1)
// NOTE: Linear time with
// https://en.wikipedia.org/wiki/Longest_palindromic_substring#Manacher's_algorithm
class Solution {
  public:
    string longestPalindrome(string s) {
        string res;

        for (int i = 0; i < s.length(); ++i) {
            // Odd-length palindromes
            int start = i, end = i;
            while (start >= 0 && end < s.length() && s[start] == s[end]) {
                string sub = s.substr(start, end - start + 1);
                if (sub.length() > res.length()) res = sub;
                start -= 1;
                end += 1;
            }

            // Even-length palindromes
            start = i, end = i + 1;
            while (start >= 0 && end < s.length() && s[start] == s[end]) {
                string sub = s.substr(start, end - start + 1);
                if (sub.length() > res.length()) res = sub;
                start -= 1;
                end += 1;
            }
        }

        return res;
    }
};
