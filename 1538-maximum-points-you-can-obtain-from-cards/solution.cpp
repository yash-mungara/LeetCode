class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n=nums.size();
        long long sum=0, ans=0;

        for(int i=0;i<k;i++){
            sum+=nums[i];
        }
        ans=sum;
        int i=k-1;
        int j=0;
        while(i>=0){
            sum-=(nums[i]-nums[n-1-j]);
            ans = max(ans,sum);
            i--;
            j++;
        }
        return (int)ans;
    }
};
