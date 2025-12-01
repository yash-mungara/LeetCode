class Solution {
public:
    bool helper(int i,int j,int m,int n,vector<vector<char>>& board, string word,int k){
        if(k==word.size()) return true;
        if(i<0 || j<0 || j==n || i==m || board[i][j]!=word[k]) return false;
        board[i][j] = '#';
        bool a = helper(i+1,j,m,n,board,word,k+1);
        bool b = helper(i-1,j,m,n,board,word,k+1);
        bool c = helper(i,j+1,m,n,board,word,k+1);
        bool d = helper(i,j-1,m,n,board,word,k+1);
        board[i][j] = word[k];
        return a || b || c || d;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m= board.size();
        int n= board[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(word[0]==board[i][j]){
                    if(helper(i,j,m,n,board,word,0)) return true;
                }
            }
        }
        return false;
    }
};
