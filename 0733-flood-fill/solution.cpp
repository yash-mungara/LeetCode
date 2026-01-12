class Solution {
public:
    void dfs(vector<vector<int>>& image, int i, int j, int op, int color) {
        int m = image.size();
        int n = image[0].size();

        if(i < 0 || i >= m || j < 0 || j >= n) return;
        if(image[i][j] != op) return;

        image[i][j] = color;

        dfs(image, i+1, j, op, color);
        dfs(image, i-1, j, op, color);
        dfs(image, i, j+1, op, color);
        dfs(image, i, j-1, op, color);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color) return image;

        dfs(image, sr, sc, image[sr][sc], color);
        return image;
    }
};

