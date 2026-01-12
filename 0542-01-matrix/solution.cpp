class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size(), n=mat[0].size();
        vector<vector<int>> ans(m,vector<int>(n,0));
        vector<vector<int>> vis(m,vector<int>(n,0));
        queue<pair<pair<int,int>, int>> q;
        int drow[] = {0,1,0,-1};
        int dclm[] = {1,0,-1,0};

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({{i,j}, 0});
                    vis[i][j] = 1;
                }
            }
        }

        while(!q.empty()){
            int i=q.front().first.first;
            int j=q.front().first.second;
            int step = q.front().second;
            q.pop();
            ans[i][j]=step;

            for(int k=0;k<4;k++){
                int nrow= i+drow[k];
                int nclm= j+dclm[k];
                if(nrow>=0 && nclm>=0 && nrow<m && nclm<n && vis[nrow][nclm]!=1){
                    vis[nrow][nclm]=1;
                    q.push({{nrow,nclm},step+1});
                }
            }
        }
        return ans;
    }
};
