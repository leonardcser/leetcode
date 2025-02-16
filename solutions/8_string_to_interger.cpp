// Time  complexity: O(n)
// Space complexity: O(1)
#include <cctype>
#include <climits>
#include <string>

class Solution {
public:
    int myAtoi(std::string s) {
        int i = 0, n = s.size();
        // Ignore leading whitespaces
        while (i < n && s[i] == ' ') i++;

        // Check sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }

        // Convert digits
        long res = 0;
        while (i < n && std::isdigit(s[i])) {
            int digit = s[i] - '0';
            
            // Check overflow
            if (res > (INT_MAX - digit) / 10) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            
            res = res * 10 + digit;
            i++;
        }

        return sign * res;
    }
};
