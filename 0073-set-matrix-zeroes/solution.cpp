class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> row,col;
        int n=matrix.size(), m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    row.insert(i);
                    col.insert(j);
                }
            }
        }

        for(auto it:row){
            int r = it;
            for(int i=0;i<m;i++){
                matrix[r][i] = 0;
            }
        }
        for(auto it:col){
            int c = it;
            for(int i=0;i<n;i++){
                matrix[i][c] = 0;
            }
        }
    }
};
