class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        while (i < n && s[i] == ' ') i++;  // skip spaces

        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        long ans = 0;  // use long to detect overflow
        while (i < n && s[i] >= '0' && s[i] <= '9') {
            ans = ans * 10 + (s[i] - '0');

            // Check for overflow
            if (sign * ans > INT_MAX) return INT_MAX;
            if (sign * ans < INT_MIN) return INT_MIN;

            i++;
        }

        return sign * ans;
    }
};
