// Time  complexity: O(n+m)
// Space complexity: O(1)
#include <vector>

using namespace std;

constexpr int MAX_CHAR = 26;

class Solution {
  public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> freq(MAX_CHAR, 0);

        for (auto ch : magazine) {
            freq[ch - 'a']++;
        }

        for (auto ch : ransomNote) {
            if (freq[ch - 'a'] <= 0) return false;

            freq[ch - 'a']--;
        }
        return true;
    }
};
