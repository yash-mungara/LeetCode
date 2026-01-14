class Solution {
private:
    int n, m;
    int drow[4] = {1, 0, -1, 0};
    int dclm[4] = {0, 1, 0, -1};

    void dfs(int i, int j, vector<vector<char>> &mat, vector<vector<int>> &vis) {
        vis[i][j] = 1;
        for (int k = 0; k < 4; k++) {
            int r = i + drow[k];
            int c = j + dclm[k];
            if (r >= 0 && r < n && c >= 0 && c < m &&
                !vis[r][c] && mat[r][c] == 'O') {
                dfs(r, c, mat, vis);
            }
        }
    }

public:
    void solve(vector<vector<char>>& mat) {
        if (mat.empty()) return;

        n = mat.size();
        m = mat[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            if (mat[i][0] == 'O' && !vis[i][0]) dfs(i, 0, mat, vis);
            if (mat[i][m-1] == 'O' && !vis[i][m-1]) dfs(i, m-1, mat, vis);
        }

        for (int j = 0; j < m; j++) {
            if (mat[0][j] == 'O' && !vis[0][j]) dfs(0, j, mat, vis);
            if (mat[n-1][j] == 'O' && !vis[n-1][j]) dfs(n-1, j, mat, vis);
        }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (mat[i][j] == 'O' && !vis[i][j])
                    mat[i][j] = 'X';
    }
};

