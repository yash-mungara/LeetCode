class Solution {
public:
    vector<string> ans;

    void solve(string &num, int target, int index, long currValue, long lastValue, string path) {
        if (index == num.size()) {
            if (currValue == target)
                ans.push_back(path);
            return;
        }

        for (int i = index; i < num.size(); i++) {
            // avoid numbers with leading zeros
            if (i != index && num[index] == '0') break;

            string part = num.substr(index, i - index + 1);
            long val = stol(part);

            if (index == 0) {
                // First number → no operator before it
                solve(num, target, i + 1, val, val, part);
            } else {
                // '+' operator
                solve(num, target, i + 1, currValue + val, val, path + "+" + part);

                // '-' operator
                solve(num, target, i + 1, currValue - val, -val, path + "-" + part);

                // '*' operator
                solve(num, target, i + 1,
                      currValue - lastValue + lastValue * val,
                      lastValue * val,
                      path + "*" + part);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        solve(num, target, 0, 0, 0, "");
        return ans;
    }
};

