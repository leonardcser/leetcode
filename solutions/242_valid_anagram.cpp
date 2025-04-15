// Time  complexity: O(n + m)
// Space complexity: O(1)
#include <string>
#include <vector>

using namespace std;

constexpr int MAX_CHAR = 26;

class Solution {
  public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        // NOTE: Using vector here is better than a map
        vector freq(MAX_CHAR, 0);

        for (auto ch : s) {
            freq[ch - 'a']++;
        }
        for (auto ch : t) {
            freq[ch - 'a']--;
        }

        for (auto f : freq) {
            if (f != 0) {
                return false;
            }
        }

        return true;
    }
};
