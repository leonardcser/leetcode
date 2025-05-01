// Time  complexity: O(n)
// Space complexity: O(1)
// NOTE: Boyer-Moore majority vote algorithm
// https://en.wikipedia.org/wiki/Boyer%E2%80%93Moore_majority_vote_algorithm
#include <vector>

using namespace std;

class Solution {
  public:
    int majorityElement(vector<int> &nums) {
        int m = 0;
        int c = 0;

        for (int x : nums) {
            if (c == 0) {
                m = x;
                c = 1;
            } else if (m == x) {
                c++;
            } else {
                c--;
            }
        }

        return m;
    }
};
