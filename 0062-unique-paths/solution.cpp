class Solution {
private: 
    void helper(int &ans, int i, int j, int &m, int &n, vector<vector<int>> &v){
        if(i>=m || i<0 || j>=n || j<0) return;
        if(i==m-1 && j==n-1){
            v[i][j] = 1;
            return;
        }
        if(v[i][j]!=0){
            return;
        }
        
        helper(ans,i+1,j,m,n,v);
        helper(ans,i,j+1,m,n,v);
        v[i][j]+= v[i+1][j]+v[i][j+1];
        return;
    }
public:
    int uniquePaths(int m, int n) {
        vector<int> v(n+1,0);
        v[n-1] = 1;
        for(int i=0;i<m;i++){
            vector<int> temp(n+1,0);
            for(int j=n-1;j>=0;j--){
                temp[j] += temp[j+1]+v[j];
            }
            v = temp;
        }
        return v[0];
        
    }
};
