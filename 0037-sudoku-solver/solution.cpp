class Solution {
public:
    bool issafe(vector<vector<char>>& board,int row,int col,char i){
        for(int j=0;j<9;j++){
            if(board[j][col]==i){
                return false;
            }
        }
        for(int j=0;j<9;j++){
            if(board[row][j]==i){
                return false;
            }
        }

        int srow = (row/3)*3, scol = (col/3)*3;
        for(int p=srow;p<=srow+2;p++){
            for(int q=scol;q<=scol+2;q++){
                if(board[p][q]==i)return false;
            }
        }
        return true;
    }
    bool helper(vector<vector<char>>& board,int row,int col){
        if(row==9)return true;
        int nrow = row, ncol= col+1;
        if(ncol==9){
            nrow++;
            ncol=0;
        }

        if(board[row][col]!='.'){
            return helper(board,nrow,ncol);
        }
        
        for(char i='1';i<='9';i++){
            if(issafe(board,row,col,i)){
                board[row][col] = i;
                if(helper(board,nrow,ncol)){return true;}
                board[row][col] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        helper(board,0,0);
        
    }
};
