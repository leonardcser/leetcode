// Time  complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.length())
            return s;

        size_t rowIdx = 0;
        // NOTE: Use a direction of travel + 2d array 
        int dir = 0; // direction of traversal (1 for downward, -1 for upward)
        vector<vector<char>> rows(numRows);

        for (char c : s) {
            rows[rowIdx].push_back(c);
            if (rowIdx == 0) {
                dir = 1;
            } else if (rowIdx == numRows - 1) {
                dir = -1;
            }
            rowIdx += dir;
        }

        string res;
        for (const auto& row : rows) {
            for (char c : row) {
                res += c;
            }
        }

        return res;
    }
};
