class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        int ans = 0, curr=0;

        for(int i=0;i<s.size();i++){
            if(m.find(s[i])==m.end()){
                ans = max(i-curr+1, ans);
                m[s[i]] = i;
            } else{
                for(int j=curr;j<m[s[i]];j++){
                    m.erase(s[j]);
                }
                curr = m[s[i]]+1;
                m[s[i]] = i;
                ans = max(i-curr+1,ans); 
            }
        }
        return ans;
    }
};
