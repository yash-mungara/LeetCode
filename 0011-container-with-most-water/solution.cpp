class Solution {
public:
    int maxArea(vector<int>& height) {
        int lp=0, rp=height.size()-1, maxW = 0;
        while(lp<rp){
            int w= rp-lp, h = min(height[lp],height[rp]);
            int Cmax = w*h;
            maxW = max(maxW,Cmax);
            if(height[lp]<height[rp]){lp++;}
            else{rp--;}
            
        }
        return maxW;
    }
};
