class Solution {
public:
    int findLargestElementInColumn(vector<vector<int>>& matrix,int &rows,int &col) {
        int index = -1;
        int maxElement = INT_MIN;
        for(int i=0; i<rows; ++i) {
            if(matrix[i][col] > maxElement) {
                maxElement = matrix[i][col];
                index = i;
            }
        }
        return index;
    }
    
    vector<int> findPeakGrid(vector<vector<int>>& matrix) {
        int rows = matrix.size() , cols = matrix[0].size();
        int low = 0 , high = cols - 1;
        while(low <= high) {
            int mid = (low + high) / 2;
            int maxRowIndex = findLargestElementInColumn(matrix,rows,mid);
            int left = mid - 1 >= 0 ? matrix[maxRowIndex][mid - 1] : -1;
            int right = mid + 1 < cols ? matrix[maxRowIndex][mid + 1] : -1;
            if(matrix[maxRowIndex][mid] > left && matrix[maxRowIndex][mid] > right) {
                return {maxRowIndex,mid};
            }
            else if(matrix[maxRowIndex][mid] < left) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return {-1,-1};
    }
};
