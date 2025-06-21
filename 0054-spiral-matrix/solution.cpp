class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int m=mat.size(), n=mat[0].size();
        int srow=0, sclm=0, erow=m-1, eclm=n-1;
        vector<int> ans;
        while(srow<=erow && sclm<=eclm){
            //upperraw
            for(int j=sclm;j<=eclm;j++){
                ans.push_back(mat[srow][j]);
            }
            //rightcolumn
            for(int i=srow+1;i<=erow;i++){
                ans.push_back(mat[i][eclm]);
            }
            //lastrow
            for(int j=eclm-1;j>=sclm;j--){
                if(srow==erow){break;}
                ans.push_back(mat[erow][j]);
            }
            //leftcolumn
            for(int i=erow-1;i>=srow+1;i--){
                if(sclm==eclm){break;}
                ans.push_back(mat[i][sclm]);
            }

            srow++;erow--;sclm++;eclm--;
        }
        return ans;
    }
};
