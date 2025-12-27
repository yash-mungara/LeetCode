class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> helper(26,0);
        for(char c:tasks) helper[c-'A']++;

        int maxf=0;
        for(int x:helper) maxf = max(maxf,x);

        int countmax=0;
        for(int f:helper) {
            if(f==maxf) countmax++;
        }

        int ans = (n+1)*(maxf-1)+countmax;
        return max(ans,(int)tasks.size());
    }
};
