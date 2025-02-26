// Time  complexity: O(n)
// Space complexity: O(n)
#include <stack>
class Solution {
  public:
    bool isValid(string s) {
        std::stack<char> stack;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                stack.push(c);
                continue;
            }
            if (stack.empty()) return false;
            const char top = stack.top();
            if (c == ')' && top != '(') return false;
            if (c == '}' && top != '{') return false;
            if (c == ']' && top != '[') return false;
            stack.pop();
        }

        return stack.empty();
    }
};
