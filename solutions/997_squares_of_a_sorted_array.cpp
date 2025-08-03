#include <cmath>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> sortedSquares(vector<int> &nums) {
        int n = nums.size();
        vector<int> result(n);
        int left = 0;
        int right = n - 1;
        int pos = n - 1;

        while (left <= right) {
            if (abs(nums[left]) > abs(nums[right])) {
                result[pos--] = pow(nums[left], 2);
                left++;
            } else {
                result[pos--] = pow(nums[right], 2);
                right--;
            }
        }

        return result;
    }
};
