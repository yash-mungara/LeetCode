class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans=0;
        vector<int> vec(26, 0);
        int l=0, r=0;

        while(r<s.size()){
            int maxfreq=0;
            vec[s[r]-'A']++;
            for(int it:vec){maxfreq = max(maxfreq, it);}

            if(r-l+1 - maxfreq <=k){
                ans = max(ans, r-l+1);
                r++;
            } else{
                vec[s[l]-'A']--;
                vec[s[r]-'A']--;
                l++;
            }
        }
        return ans;
    }
};
