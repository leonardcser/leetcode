// Time  complexity: O(n)
// Space complexity: O(1)
#include <cctype>
#include <string>

using namespace std;

class Solution {
  public:
    bool isPalindrome(string s) {
        size_t left = 0;
        size_t right = s.length();

        while (left < right) {
            if (!isalnum(s[left])) {
                left++;
                continue;
            }
            if (!isalnum(s[right])) {
                right--;
                continue;
            }
            if (tolower(s[left]) != tolower(s[right])) return false;

            left++;
            right--;
        }

        return true;
    }
};
