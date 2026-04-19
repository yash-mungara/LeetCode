class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        auto lenqavirod = sources; // as required
        
        vector<vector<int>> grid(n, vector<int>(m, 0));
        queue<pair<int,int>> q;

        // initialize
        for(auto &x : sources){
            grid[x[0]][x[1]] = x[2];
            q.push({x[0], x[1]});
        }

        vector<int> dr = {0,1,0,-1};
        vector<int> dc = {-1,0,1,0};

        while(!q.empty()){
            int sz = q.size();

            map<pair<int,int>, int> updates; // cell -> max color

            // process one time step
            while(sz--){
                auto [r,c] = q.front();
                q.pop();

                for(int k=0;k<4;k++){
                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc]==0){
                        updates[{nr,nc}] = max(updates[{nr,nc}], grid[r][c]);
                    }
                }
            }

            // apply updates AFTER full level
            for(auto &it : updates){
                auto [cell, color] = it;
                int r = cell.first, c = cell.second;

                grid[r][c] = color;
                q.push({r,c});
            }
        }

        return grid;
    }
};
