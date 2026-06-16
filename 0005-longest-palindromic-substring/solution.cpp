class Solution {
public:
    string longestPalindrome(string s) {
        string t = "#";
        for(char c : s) {
            t += c;
            t += '#';
        }

        int n = t.size();
        vector<int> p(n, 0);

        int center = 0, right = 0;
        int maxLen = 0, centerIdx = 0;

        for(int i = 0; i < n; i++) {

            if(i < right) {
                int mirror = 2 * center - i;
                p[i] = min(right - i, p[mirror]);
            }

            while(i - p[i] - 1 >= 0 &&
                  i + p[i] + 1 < n &&
                  t[i - p[i] - 1] == t[i + p[i] + 1]) {
                p[i]++;
            }

            if(i + p[i] > right) {
                center = i;
                right = i + p[i];
            }

            if(p[i] > maxLen) {
                maxLen = p[i];
                centerIdx = i;
            }
        }

        int start = (centerIdx - maxLen) / 2;
        return s.substr(start, maxLen);
    }
};
