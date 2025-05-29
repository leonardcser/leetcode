// Time  complexity: O(1)
// Space complexity: O(1)
constexpr int MASK = 0x1;

class Solution {
  public:
    int hammingWeight(int n) {
        int w = 0;
        while (n) {
            w += n & MASK;
            n = n >> 1;
        }

        return w;
    }
};
