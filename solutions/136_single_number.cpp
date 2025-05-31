// Time  complexity: O(n)
// Space complexity: O(1)
// NOTE: XOR is commutative and associative, so order doesn’t matter
#include <vector>

using namespace std;

class Solution {
  public:
    int singleNumber(vector<int> &nums) {
        int res = 0;
        for (int num : nums) {
            res ^= num;
        }
        return res;
    }
};
