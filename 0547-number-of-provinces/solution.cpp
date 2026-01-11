class Solution {
public:
    void helper(vector<vector<int>> &adjls, int i, vector<int> &vis){
        vis[i] = 1;
        for(auto it : adjls[i]){
            if(!vis[it]) helper(adjls,it,vis);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>> adjls(n);

            for(int i=0;i<isConnected.size();i++){
                for(int j=0;j<isConnected[0].size();j++){
                    if(isConnected[i][j]==1 && i!=j){
                        adjls[i].push_back(j);
                        adjls[j].push_back(i);
                    }
                }
            }
        
        vector<int> vis(adjls.size(),0);
        int cnt=0;
            for(int i=0;i<adjls.size();i++){
                if(vis[i]==0){
                    cnt++;
                    helper(adjls,i,vis);
                }
            }
        return cnt;
    }
};
