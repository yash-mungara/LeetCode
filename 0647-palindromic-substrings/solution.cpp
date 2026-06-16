class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size(),
        ans = 0;

        for(int i=0;i<n;i++){
            ans++;
            int left=i-1, right=i+1;
            while(left>=0 && right<n && s[left]==s[right]){
                left--; right++;
                ans++;
            }
        }

        for(int i=0,j=1;j<n;i++,j++){
            if(s[i]!=s[j]) continue;
            ans++;
            int left=i-1, right=j+1;
            while(left>=0 && right<n && s[left]==s[right]){
                left--; right++;
                ans++;
            }
        }
        return ans;
    }
};
