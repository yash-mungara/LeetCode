class Solution {
public:
    vector<int> r = {0,1,0,-1}, c = {1,0,-1,0};
    bool isvalid(int i, int j, int n, int m){
        return i>=0 && i<n && j>=0 && j<m;
    }
    bool dfs(vector<vector<char>>& board, int i, int j, int idx, string &word){
        if(idx==word.size()-1) return true;
        char temp = board[i][j];
        board[i][j] = '#';

        for(int k=0;k<4;k++){
            int nr = i+r[k], nc = j+c[k];
            if(isvalid(nr,nc,board.size(), board[0].size()) && word[idx+1]==board[nr][nc]){
                if(dfs(board, nr,nc, idx+1, word)){
                    board[i][j] = temp;
                    return true;
                }
            }
        }

        board[i][j] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m=board[0].size();
        bool ans = false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == word[0]){
                    if(dfs(board, i, j, 0, word)) return true;
                }
            }
        }

        return false;
    }
};
