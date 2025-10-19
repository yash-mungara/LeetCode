class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n <= 1) return s;

        string ans = "";

        for (int i = 0; i < n; i++) {
            // Odd length palindrome (center = i)
            int low = i, high = i;
            while (low >= 0 && high < n && s[low] == s[high]) {
                if (high - low + 1 > ans.size()) {
                    ans = s.substr(low, high - low + 1);
                }
                low--;
                high++;
            }

            // Even length palindrome (center between i and i+1)
            low = i; high = i + 1;
            while (low >= 0 && high < n && s[low] == s[high]) {
                if (high - low + 1 > ans.size()) {
                    ans = s.substr(low, high - low + 1);
                }
                low--;
                high++;
            }
        }

        return ans;
    }
};

