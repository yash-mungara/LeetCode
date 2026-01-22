class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size(), m=heights[0].size();
        set<pair<int,int>> s;
        vector<vector<int>> aft(n,vector<int> (m,1e9));
        vector<int> nrow = {0,1,0,-1}, nclm = {1,0,-1,0};

        s.insert({0,0});
        aft[0][0] = 0;
        while(!s.empty()){
            int i = s.begin()->first, j=s.begin()->second;
            s.erase(s.begin());
            
            for(int k=0;k<4;k++){
                int ni = i+nrow[k], nj = j+nclm[k];
                if(ni>=0 && nj>=0 && ni<n && nj<m){
                    int afrt = abs(heights[ni][nj]-heights[i][j]);
                    int newaft = max(afrt,aft[i][j]);

                    if(newaft<aft[ni][nj]){
                        if(aft[i][j]!=1e9) s.erase({ni,nj});    

                        aft[ni][nj] = newaft;
                        s.insert({ni,nj});
                    }
                }
            }
        }
        return aft[n-1][m-1];
    }
};
