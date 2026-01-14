class Solution {
private:
    int drow[4] = {0,1,0,-1};
    int dclm[4] = {1,0,-1,0};
    int m,n;
    void dfs(int i,int j,vector<vector<int>> &vis, vector<vector<int>> &grid){
        vis[i][j]=1;
        for(int k=0;k<4;k++){
            int r= i+ drow[k];
            int c= j+ dclm[k];

            if(r>=0 && c>=0 && r<n && c<m && !vis[r][c] && grid[r][c]==1){
                dfs(r,c,vis,grid);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        n=grid.size(); m=grid[0].size();
        
        int ans=0;
        vector<vector<int>> vis(n, vector<int>(m,0));

        for(int i=0;i<n;i++){
            if(!vis[i][0] && grid[i][0]==1)    {dfs(i,0,vis,grid);}
            if(!vis[i][m-1] && grid[i][m-1]==1){dfs(i,m-1,vis,grid);}
        }
        for(int j=0;j<m;j++){
            if(!vis[0][j] && grid[0][j]==1)     dfs(0,j,vis,grid);
            if(!vis[n-1][j] && grid[n-1][j]==1) dfs(n-1,j,vis,grid);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    ans++;
                }
            }
        }
        return ans;
    }
};
