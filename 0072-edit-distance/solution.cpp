class Solution {
public:
    int f(int i1,int i2, string &word1, string &word2){
        if(i1<0) return i2+1;
        if(i2<0) return i1+1;
        if(word1[i1]==word2[i2]) return f(i1-1,i2-1,word1,word2);
        int x,y,z;
        x=f(i1,i2-1,word1,word2); y=f(i1-1,i2-1,word1,word2); z=f(i1-1,i2,word1,word2);
        return 1+min(x,min(y,z));
    }
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2=word2.size();
        vector<int> prev(n2+1,0), curr(n2+1,0);
        for(int i=1;i<=n2;i++){
            prev[i] = i;
        }
        for(int i1=1;i1<=n1;i1++){
            curr[0] = i1;
            for(int i2=1;i2<=n2;i2++){
                if(word1[i1-1]==word2[i2-1]) curr[i2] = prev[i2-1];
                else {int x,y,z;
                x=curr[i2-1]; y=prev[i2-1]; z=prev[i2];
                curr[i2] = 1+min(x,min(y,z));}
            }
            prev = curr;
        }
        return prev[n2];
    }
};
