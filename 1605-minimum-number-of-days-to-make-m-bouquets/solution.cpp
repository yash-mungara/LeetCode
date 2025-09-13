class Solution {
public:
    int minDays(vector<int>& nums, int m, int k) {
        int n = nums.size();
        if((long long)n<(long long)m*k) return -1;
        int st = 1, end = *max_element(nums.begin(),nums.end()), mid, ans; 

        while(st<=end){
            mid = st + (end-st)/2;
            int y=m, i=0;
            while(i<n && y>0){
                int j=k;
                while(i<n && j>0){
                    if(nums[i]-mid<=0){j--;i++;}
                    else {i++;break;}
                }
                if(j==0)y--;
            }   
            if(y<=0) {end = mid-1; ans = mid;}
            else st = mid+1;
        }
        return ans;
    }
};
