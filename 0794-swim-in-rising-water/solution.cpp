class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<>> pq;
        vector<vector<int>> vis(n, vector<int> (n,0));

        pq.push({grid[0][0],{0,0}});

        int dr[] = {0,1,0,-1};
        int dc[] = {1,0,-1,0};

        while(!pq.empty()){
            auto [time,pos] = pq.top();
            pq.pop();

            int r=pos.first, c=pos.second;

            if(vis[r][c]) continue;
            vis[r][c] = 1;

            if(r==n-1 && c==n-1) return time;

            for(int i=0;i<4;i++){
                int nr = r+dr[i], nc = dc[i]+c;

                if(nr<n && nc<n && nc>=0 && nr>=0 && !vis[nr][nc]){
                    pq.push({max(grid[nr][nc],time),{nr,nc}});
                }
            }
        }
        return -1;
    }
};
