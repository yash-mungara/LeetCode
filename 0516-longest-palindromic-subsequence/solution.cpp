class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string text1 = s, text2 = text1;
        reverse(text1.begin(),text1.end());
        int n1 = text1.size(), n2 = text2.size();
        vector<int> prev(n2,0);
        for(int i1=0;i1<n1;i1++){
            vector<int> curr(n2,0);

            for(int i2=0;i2<n2;i2++){
                if(text1[i1]==text2[i2]) {
                    if(i1==0 || i2==0) curr[i2] = 1;
                    else curr[i2] = 1 + prev[i2-1];
                }
                else {
                    int p=0,q=0;
                    if(i1>0) p = prev[i2];
                    if(i2>0) q = curr[i2-1];
                    curr[i2] = max(p,q);
                }
            }
            prev = curr;
        }
        return prev[n2-1];
    }
};
