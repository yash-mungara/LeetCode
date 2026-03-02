class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> first(26, -1), last(26, -1);

        // Step 1: Find first and last occurrence
        for(int i = 0; i < n; i++) {
            if(first[s[i]-'a'] == -1)
                first[s[i]-'a'] = i;
            last[s[i]-'a'] = i;
        }

        vector<pair<int,int>> intervals;

        // Step 2: Build intervals (graph expansion idea)
        for(int c = 0; c < 26; c++) {
            if(first[c] == -1) continue;

            int l = first[c];
            int r = last[c];
            bool valid = true;

            for(int i = l; i <= r; i++) {
                int ch = s[i] - 'a';
                if(first[ch] < l) {
                    valid = false;
                    break;
                }
                r = max(r, last[ch]);
            }

            if(valid)
                intervals.push_back({l, r});
        }

        // Step 3: Greedy pick non-overlapping intervals
        sort(intervals.begin(), intervals.end(),
             [](auto &a, auto &b){
                 return a.second < b.second;
             });

        vector<string> ans;
        int prevEnd = -1;

        for(auto &it : intervals) {
            if(it.first > prevEnd) {
                ans.push_back(s.substr(it.first, it.second - it.first + 1));
                prevEnd = it.second;
            }
        }

        return ans;
    }
};
