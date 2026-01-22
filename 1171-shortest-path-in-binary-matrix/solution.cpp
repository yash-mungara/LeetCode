class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1) return -1;

        int n=grid.size();
        queue<pair<int,int>> q;
        vector<vector<int>> dis(n, vector<int> (n,0));
        int drow[] = {0,1,0,-1,1,1,-1,-1};
        int dclm[] = {1,0,-1,0,-1,1,-1,1};

        q.push({0,0});
        dis[0][0] = 1;

        while(!q.empty()){
            int i = q.front().first, j=q.front().second;
            int dist = dis[i][j];
            q.pop();

            for(int k=0;k<8;k++){
                int ni = i + drow[k];
                int nj = j + dclm[k];
                if(ni>=0 && nj>=0 && ni<n && nj<n && grid[ni][nj]==0 && dis[ni][nj]==0){
                    q.push({ni,nj});
                    dis[ni][nj] = dist+1;
                }
            }
        }
        if(dis[n-1][n-1]==0) dis[n-1][n-1]=-1;
        return dis[n-1][n-1];
    }
};
