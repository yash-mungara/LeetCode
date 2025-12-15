class Solution {
public:
    int totalFruit(vector<int>& f) {
        int ans=0, temp=1, a=f[0],idx;

        int i=0;
        while(i<f.size() && f[i]==a) {
            i++;
            temp++;
        }
        if(i==f.size()) return f.size();
        int b=f[i];
        idx=i;
        i++;
        while(i<f.size()){
            if(f[i]==a || f[i]==b){
                temp++;
            } else{
                ans=max(ans,temp);
                temp = i-idx+1;
                a=f[idx];
                b=f[i];
            }
            if(f[i]!=f[i-1]) idx=i;
            i++;
        }
        return max(ans,temp);
    }
};  
