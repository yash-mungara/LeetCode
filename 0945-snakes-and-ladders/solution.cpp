class Solution {
public:
    pair<int, int> getrc(int num, int n){
        int row = (num-1)/n, col = (num-1)%n;
        if(row%2==1){
            col = n-col-1;
        }
        row = n-1-row;
        return {row,col};   
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        queue<pair<int, int>> q;
        vector<int> vis(n*n+1, false);

        q.push({1,0});
        vis[1] = true;

        while(!q.empty()){
            auto [curr, moves] = q.front(); q.pop();

            if(curr==n*n) return moves;

            for(int i=1;i<=6 && i+curr<=n*n; i++){
                int next = curr+i;

                auto [r,c] = getrc(next,n);

                if(board[r][c]!=-1) next = board[r][c];

                if(!vis[next]){
                    q.push({next, moves+1});
                    vis[next] = true;
                } 
            }
        }
    return -1;
    }
};
