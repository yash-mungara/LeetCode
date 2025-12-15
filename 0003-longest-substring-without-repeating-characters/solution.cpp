class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=i;
        unordered_map<char,int> m;
        int ans=0;
        while(j<s.size()){
            if(m.find(s[j]) == m.end()) m[s[j]] = j;
            else {
                ans = max(ans,j-i);
                int temp = i;
                i=m[s[j]]+1;
                while(temp<i) {m.erase(s[temp]); temp++;}
                m[s[j]] = j;
            }
            j++;
        }
        ans = max(ans,j-i);
        return ans;
    }
};
