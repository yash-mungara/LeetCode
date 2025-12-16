class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans=0, i=0, j=0, maxf=0;
        vector<int> arr(26,0);

        while(j<s.size()){
            arr[s[j]-'A']++;
            maxf = max(maxf,arr[s[j]-'A']);
            
            if(j-i+1-maxf<=k) {
                ans = max(ans,j-i+1);
            } else{
                arr[s[i]-'A']--;
                for(int x:arr) maxf = max(maxf,x);
                i++;
            }
            j++;
        }
        return ans;
    }
};
