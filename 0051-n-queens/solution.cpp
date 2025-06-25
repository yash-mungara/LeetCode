class Solution {
public:
    bool issafe(vector<string> &board,int r,int j, int n){
        for(int i=0;i<n;i++){
            if(board[r][i]=='Q')return false;
        }
        for(int i=0;i<n;i++){
            if(board[i][j]=='Q')return false;
        }
        for(int p=r,q=j;p>=0 && q>=0;p--,q--){
            if(board[p][q]=='Q')return false;
        }
        for(int p=r,q=j;p>=0 && q<n;p--,q++){
            if(board[p][q]=='Q')return false;
        }
        return true;
    }
    void nqueens(vector<string> &board,int r,int n,vector<vector<string>>& ans){
        if(r==n){
            ans.push_back(board);
            return;
        }

        for(int i=0;i<n;i++){
            if(issafe(board,r,i,n)){
                board[r][i] = 'Q';
                nqueens(board,r+1,n,ans);
                board[r][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        vector<vector<string>> ans;
        nqueens(board,0,n,ans);
        return ans;
    }
};
