class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> row;
        vector<int> clm;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    row.push_back(i);
                    clm.push_back(j);
                }
            }
        }
        for(auto x:row){
            for(int k=0;k<matrix[0].size();k++){
                    matrix[x][k] = 0;
                }
        }
        for(auto x:clm){
            for(int y=0;y<matrix.size();y++){
                    matrix[y][x] = 0;
                }
        }
    return;
    }
};
