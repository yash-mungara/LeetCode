class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=0, j=matrix.size()-1, k=matrix[0].size()-1;
        if(j==0 && k==0){
            if(target==matrix[j][k])return true;
            else return false;
        }
        while(i<j){
            int y = i + (j-i)/2;
            if(target<matrix[y][0])j=y-1;
            else if(target>matrix[y][k])i=y+1;
            else j=y;
        }
        if(j<0 || i>matrix.size()-1){return false;}
        i=0;
        while(i<=k){
            int y = i + (k-i)/2;
            if(target>matrix[j][y])i=y+1;
            else if(target<matrix[j][y])k=y-1;
            else return true;
        }

        return false;
    }
};
