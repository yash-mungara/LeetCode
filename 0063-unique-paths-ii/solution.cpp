class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<long long> v(n+1,0);
        v[n-1]=1;

        for(int i=0;i<m;i++){
            vector<long long> temp(n+1,0);
            for(int j=n-1;j>=0;j--){
                if(obstacleGrid[m-1-i][j]==1) continue;
                else{
                    temp[j] += temp[j+1]+v[j];
                }
            }
            v = temp;
        }
        return (int)v[0];
    }
};
