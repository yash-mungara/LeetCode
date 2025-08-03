class Solution {
public:
    void rotate(vector<int>& v, int k) {
        int n = k%v.size();
        if(n==0) return;
        else{
        reverse(v.begin(),v.end());
        reverse(v.begin(),v.begin()+n);
        reverse(v.begin()+n,v.end());
        }
    }
};
