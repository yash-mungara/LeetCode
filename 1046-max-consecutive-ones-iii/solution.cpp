class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans=0, temp=ans;
        queue<int> q;
        for(int i=0;i<nums.size();i++){
            if(k>0 && nums[i]==0){
                q.push(i);
                temp++;
                k--;
                ans = max(ans,temp);
                continue;
            }
            if(nums[i]==1){
                temp++;
                ans = max(ans,temp);
                continue;
            }
            if(q.empty() && k==0) temp=0;
            if(k==0 && nums[i]==0){
                if(temp > i-q.front()){
                    temp=i-q.front();
                    ans = max(ans,temp);
                }
                q.pop();
                q.push(i);
                continue;
            }
        }
        return ans;
    }
};
