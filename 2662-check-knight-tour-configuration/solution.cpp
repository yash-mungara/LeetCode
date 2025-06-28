class Solution {
public:
    bool is(vector<vector<int>>& grid, int row, int clm,int ans,int n){

        if(row<0 || row>=n || clm<0 || clm>=n || grid[row][clm] != ans)return false;
        
        if(grid[row][clm] == n*n -1) return true;

        int ans1 = is(grid,row+2,clm+1,ans+1,n);
        int ans2 = is(grid,row+1,clm+2,ans+1,n);
        int ans3 = is(grid,row+2,clm-1,ans+1,n);
        int ans4 = is(grid,row+1,clm-2,ans+1,n);
        int ans5 = is(grid,row-2,clm+1,ans+1,n);
        int ans6 = is(grid,row-1,clm+2,ans+1,n);
        int ans7 = is(grid,row-2,clm-1,ans+1,n);
        int ans8 = is(grid,row-1,clm-2,ans+1,n);    

        return ans1 || ans2 || ans3 || ans4 || ans5 || ans6 || ans7 || ans8;
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        return is(grid,0,0,0,grid.size());
    }
};
