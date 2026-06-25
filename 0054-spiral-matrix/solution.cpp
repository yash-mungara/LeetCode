class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size(), m=matrix[0].size(), rs=-1, re=n, cs=-1, ce=m, r=0, c=0;
        bool right = true, left = false, down = false, up = false;
        while(ans.size()< n*m){
            if(right){
                ans.push_back(matrix[r][c]);
                c++;
                if(c==ce){
                    c--;
                    r++;
                    rs++;
                    right = false;
                    down = true;
                }
            } else if(down){
                ans.push_back(matrix[r][c]);
                r++;
                if(r==re){
                    r--;
                    c--;
                    ce--;
                    down = false;
                    left = true;
                }
            } else if(left){
                ans.push_back(matrix[r][c]);
                c--;
                if(c==cs){
                    c++;
                    r--;
                    re--;
                    left = false;
                    up = true;
                }
            } else if(up){
                ans.push_back(matrix[r][c]);
                r--;
                if(r==rs){
                    r++;
                    c++;
                    cs++;
                    up = false;
                    right = true;
                }
            }
        }
        return ans;
    }
};
