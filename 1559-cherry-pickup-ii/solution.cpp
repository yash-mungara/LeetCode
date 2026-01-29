class Solution {
public: 
    int helper(int r, int j1, int j2, int m, int n, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp){
        if(j1<0 || j2<0 || j1>=n || j2>=n) return -1e8;

        if(r==m-1) {
            if(j1==j2) return grid[r][j1];
            else return grid[r][j1]+grid[r][j2];
        }

        if(dp[r][j1][j2]!=-1) return dp[r][j1][j2];
        int maxi = -1e8;
        for(int dj1=-1;dj1<=1;dj1++){
            for(int dj2=-1;dj2<=1;dj2++){
                int value=0;
                if(j1==j2) value = grid[r][j1];
                else value = grid[r][j1]+grid[r][j2];
                value += helper(r+1,j1+dj1,j2+dj2,m,n,grid,dp);
                maxi = max(value,maxi);
            }
        }
        return dp[r][j1][j2] = maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>> front(n, vector<int> (n)), back(n, vector<int> (n));
        
        for(int j1=0;j1<n;j1++){
            for(int j2=0;j2<n;j2++){
                if(j1==j2) back[j1][j2] = grid[m-1][j1];
                else back[j1][j2] = grid[m-1][j1]+grid[m-1][j2]; 
            }
        }

        for(int r=m-2;r>=0;r--){
            for(int j1=0;j1<n;j1++){
                for(int j2=0;j2<n;j2++){
                    int maxi = -1e8;
                    for(int dj1=-1;dj1<=1;dj1++){
                        for(int dj2=-1;dj2<=1;dj2++){
                            int value=0;
                            if(j1==j2) value = grid[r][j1];
                            else value = grid[r][j1]+grid[r][j2];
                            if(dj1+j1>=0 && dj1+j1<n && dj2+j2<n && dj2+j2>=0) value += back[dj1+j1][dj2+j2];
                            else value += -1e8;
                            maxi = max(value,maxi);
                        }
                    }
                    front[j1][j2] = maxi;
                }
            }
            back = front;
        }
        return back[0][n-1];

    }
};
