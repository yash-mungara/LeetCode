class Solution {
public:
    string removeKdigits(string nums, int k) {
        string ans;
        stack<char> st;
        int i=0;
        if(nums.size()==k) {
            ans+="0";
            return ans;
        }
        while(i<nums.size()){
            while(k>0 && !st.empty() && st.top()>nums[i]){
                st.pop();
                k--;
            }
            if(k>0 && !st.empty() && nums[i]>st.top() && nums[i]>nums[i+1]) {i++;k--;continue;}
            st.push(nums[i]);
            i++;
        }
        while(k>0 && !st.empty()){
            st.pop();k--;
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        i=ans.size()-1;
        while(i>=0){
            if(ans[i]!='0') break;
            ans.pop_back();
            i--;
        }
        if(ans.size()==0) ans+="0";
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
