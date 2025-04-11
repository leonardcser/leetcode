// Time  complexity: O(n)
// Space complexity: O(1)
// NOTE: Modification of the Kadane's algorithm
// https://en.wikipedia.org/wiki/Maximum_subarray_problem#Computing_the_best_subarray's_position

#include <algorithm>
#include <limits>
#include <vector>

using namespace std;

class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() <= 1) return 0;

        int min_curr_price = numeric_limits<int>::max();
        int max_curr_return = 0;

        for (size_t i = 0; i < prices.size(); i++) {
            min_curr_price = min(prices.at(i), min_curr_price);
            max_curr_return =
                max(prices.at(i) - min_curr_price, max_curr_return);
        }

        return max_curr_return;
    }
};
