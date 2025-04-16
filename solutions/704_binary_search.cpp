// Time  complexity: O(log(n))
// Space complexity: O(1)
#include <vector>

using namespace std;

class Solution {
  public:
    int search(vector<int> &nums, int target) {
        int lo = 0;
        int hi = nums.size() - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums.at(mid) == target) {
                return mid;
            }
            if (nums.at(mid) < target) {
                lo = mid + 1;

            } else {
                hi = mid - 1;
            }
        }
        return -1;
    }
};
