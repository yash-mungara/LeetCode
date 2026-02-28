class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        queue<pair<pair<int,int>,int>> q;       // {{i,j},time}
        vector<int> cr = {1,0,-1,0}, cc = {0,1,0,-1};
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2) q.push({{i,j},0});
            }
        }

        while(!q.empty()){
            ans = q.front().second; int i= q.front().first.first, j= q.front().first.second;
            q.pop();
            for(int k=0;k<4;k++){
                int ni = i + cr[k], nj = j + cc[k];
                if(ni>=0 && ni<n && nj>=0 && nj<m && grid[ni][nj]==1){
                    grid[ni][nj] = 2;
                    q.push({{ni,nj},ans+1});
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return ans;
    }
};
