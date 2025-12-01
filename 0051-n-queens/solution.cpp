class Solution {
public:
    bool issafe(int row, int clm, vector<string> board, int n){
        int a=row;
        int b=clm;

        while(row>=0 && clm>=0){
            if(board[row][clm]=='Q') return false;
            row--; clm--;
        }

        row=a; clm=b;

        while(row<n && clm>=0){
            if(board[row][clm]=='Q') return false;
            row++; clm--;
        }

        while(b>=0){
            if(board[a][b]=='Q') return false;
            b--;
        }
        return true;
    }
    void solve(int clm, vector<string>& board, vector<vector<string>>& ans, int n){
        if(clm == n){
            ans.push_back(board);
            return;
        }
        
        for(int row=0;row<n;row++){
            if(issafe(row,clm,board,n)){
                board[row][clm] = 'Q';
                solve(clm+1,board,ans,n);
                board[row][clm] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i] = s;
        }
        solve(0,board,ans,n);
        return ans;
    }
};
