class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        queue<pair<string, pair<int, int>>> q;
        q.push({"", {0, 0}});
        
        while (!q.empty()) {
            auto [s, p] = q.front(); q.pop();
            int open = p.first, close = p.second;

            if (open == n && close == n) {
                ans.push_back(s);
                continue;
            }

            if (open < n) q.push({s + "(", {open + 1, close}});
            if (close < open) q.push({s + ")", {open, close + 1}});
        }

        return ans;
    }
};


