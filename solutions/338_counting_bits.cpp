// Time  complexity: O(n)
// Space complexity: O(1)
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0);
        for (int i = 0; i <= n; ++i) {
            // ans[i >> 1] is the number of 1s in i / 2
            // (i % 2) adds the 1 if the LSB of i is 1
            ans[i] = ans[i >> 1] + (i % 2);
        }
        return ans;
    }
};
