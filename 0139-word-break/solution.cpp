class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,bool> memo;
        return solve(s, wordDict, memo);
    }
    bool solve(string s, vector<string>& wordDict, unordered_map<string,bool>& memo) {
        if (s.size() == 0) return true;
        if (memo.count(s)) return memo[s];

        for (int i = 1; i <= s.size(); i++) {
            string prefix = s.substr(0, i);
            if (find(wordDict.begin(), wordDict.end(), prefix) != wordDict.end()) {
                if (solve(s.substr(i), wordDict, memo)) {
                    return memo[s] = true;
                }
            }
        }

        return memo[s] = false;
    }
};
