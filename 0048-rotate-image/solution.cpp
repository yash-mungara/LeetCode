class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++){
            for(int j=i;j<matrix.size();j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        int st=0, end=matrix.size()-1;
        for(int k=0;k<matrix.size();k++){
            while(st<=end){
                swap(matrix[k][st],matrix[k][end]);
                st++;end--;
            }
            st=0;
            end=matrix.size()-1;
        }
    }
};
