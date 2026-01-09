class Solution {
public:
    int myAtoi(string s) {
        long result = 0;
        int i = 0, n = s.size();
        int sign = 1;

        // Skip leading spaces
        while (i < n && s[i] == ' ') i++;

        // Check sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Process digits
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            // Overflow check for 32-bit signed integer
            if (result > INT_MAX / 10 || 
               (result == INT_MAX / 10 && digit > INT_MAX % 10)) {
                return (sign == 1 ? INT_MAX : INT_MIN);
            }

            result = result * 10 + digit;
            i++;
        }

        return (int)result * sign;
    }
};
