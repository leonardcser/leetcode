// Time  complexity: O(n+m)
// Space complexity: O(n+m)
#include <string>

using namespace std;

class Solution {
  public:
    bool backspaceCompare(string s, string t) {
        return computeString(s) == computeString(t);
    }

  private:
    string computeString(string s) {
        string res;

        for (char c : s) {
            if (c != '#') {
                res += c;
            } else if (!res.empty()) {
                res.pop_back();
            }
        }

        return res;
    }
};
