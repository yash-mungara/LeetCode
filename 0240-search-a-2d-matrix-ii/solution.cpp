class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int target) {
        int i=0, j=a[0].size()-1;
        while(j>=0 && i<a.size()){
            if(target<a[i][j]) j--;
            else if(target>a[i][j]) i++;
            else return true;
        }
        return false;
    }
};
