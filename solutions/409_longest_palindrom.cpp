// Time  complexity: O(n)
// Space complexity: O(1)
#include <string>

using namespace std;

constexpr int ALPHABET_LEN = 26;

class Solution {
  public:
    int longestPalindrome(string s) {
        int lower[ALPHABET_LEN] = {0};
        int upper[ALPHABET_LEN] = {0};

        for (char ch : s) {
            if (ch >= 'a') {
                lower[ch - 'a']++;
            } else {
                upper[ch - 'A']++;
            }
        }

        int count = 0;
        int odd = 0;
        for (int i = 0; i < ALPHABET_LEN; i++) {
            if (lower[i] % 2 == 0) {
                count += lower[i];
            } else {
                count += lower[i] - 1;
                odd = 1;
            }

            if (upper[i] % 2 == 0) {
                count += upper[i];
            } else {
                count += upper[i] - 1;
                odd = 1;
            }
        }

        return count + odd;
    }
};
