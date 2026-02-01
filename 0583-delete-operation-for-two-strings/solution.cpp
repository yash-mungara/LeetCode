class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1=word1.size(), n2=word2.size();
        vector<int> prev(n2,0);
        for(int i1=0;i1<n1;i1++){
            vector<int> curr(n2,0);

            for(int i2=0;i2<n2;i2++){
                if(word1[i1]==word2[i2]) {
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
        int cl = prev[n2-1];
        return n1+n2-2*cl;
    }
};
