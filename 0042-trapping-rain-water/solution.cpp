class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), l=0, r=n-1,
        lmax = 0, ans = 0,
        rmax = 0;

        while(l<r){
            lmax = max(height[l],lmax);
            rmax = max(height[r],rmax);

            if(lmax<rmax){
                ans+= lmax - height[l];l++;
            }
            else{
                ans+= rmax - height[r];r--;
            }
        }
        return ans;
    }
};
