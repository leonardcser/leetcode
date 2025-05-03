// Time  complexity: O(1)
// Space complexity: O(1)
constexpr double phi = 1.6180339887498949;
constexpr double sqrt5 = 2.2360679774997898;

class Solution {
public:
    int climbStairs(int n) {
        return round((pow(phi, n+1) - pow(1 - phi, n+1)) / sqrt5);
    }
};
