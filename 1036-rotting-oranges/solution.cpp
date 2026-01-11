class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n= grid.size(), m=grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cntf=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                } else vis[i][j] = 0;
                if(grid[i][j] == 1) cntf++;
            }
        }

        int tm=0;
        int drow[] = {-1,0,1,0};
        int dclm[] = {0,-1,0,1};
        int cnt=0;
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            tm = max(tm,t);
            q.pop();
            for(int i=0;i<4;i++){
                int nrow = r + drow[i];
                int nclm = c + dclm[i];
                if(nrow>=0 && nrow<n && nclm>=0 && nclm<m && vis[nrow][nclm]!=2 && 
                grid[nrow][nclm]==1){
                    q.push({{nrow,nclm},t+1});
                    vis[nrow][nclm] = 2;
                    cnt++;
                }
            }
        }
        if(cnt!=cntf) return -1;
        else return tm;
    }
};
