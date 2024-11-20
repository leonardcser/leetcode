// Time  complexity: O(n)
// Space complexity: O(n)
class Solution {
  public:
    vector<int> twoSum(vector<int> &nums, int target) {
        // Base case
        if (nums.size() == 2) {
            return {0, 1};
        }

        unordered_map<int, int> num_map;
        num_map[nums[0]] = 0;
        for (int i = 1; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (num_map.count(complement)) {
                return {num_map[complement], i};
            }
            num_map[nums[i]] = i;
        }
        // Not found
        return {};
    }
};
