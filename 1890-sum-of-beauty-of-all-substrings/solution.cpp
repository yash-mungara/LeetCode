class Solution {
public:
    int beautySum(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            unordered_map<char,int> m;
            for(int j=i;j<n;j++){
                m[s[j]]++;
                int maxi=INT_MIN, mini=INT_MAX;
                for(auto [character,freq]:m)
                maxi=max(maxi,freq) ,mini=min(mini,freq);
                ans+=maxi-mini;
            }
        }
        return ans;
    }
};
