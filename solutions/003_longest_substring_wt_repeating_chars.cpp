// Time  complexity: O(n)
// Space complexity: O(1)
class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
        // NOTE: We keep track of two pointers of the slice
        // and how many chars we encountered
        vector<int> last_index(128, -1); // Array for ASCII characters
        int max_length = 0, start = 0;

        for (int end = 0; end < s.length(); ++end) {
            if (last_index[s[end]] >= start) {
                start = last_index[s[end]] + 1;
            }
            last_index[s[end]] = end;
            max_length = max(max_length, end - start + 1);
        }

        return max_length;
    }
};
