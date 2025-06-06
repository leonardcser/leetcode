// Time  complexity: O(n)
// Space complexity: O(1)
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.empty()) return "";
        if (strs.size() == 1) return strs[0];

        string prefix;
        for (int i = 0; i < strs[0].size(); ++i) {
            char curr_char = strs[0][i];
            for (int j = 1; j < strs.size(); ++j) {
                if (i >= strs[j].size() || strs[j][i] != curr_char)
                    return prefix;
            }
            prefix += curr_char;
        }

        return prefix;
    }
};
