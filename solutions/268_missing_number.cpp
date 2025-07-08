#include <numeric>
#include <vector>

using namespace std;

class Solution {
  public:
    int missingNumber(vector<int> &nums) {
        int n = nums.size();

        int actual_sum = (n * (n + 1)) / 2;
        int nums_sum = std::accumulate(nums.begin(), nums.end(), 0);

        return actual_sum - nums_sum;
    }
};
