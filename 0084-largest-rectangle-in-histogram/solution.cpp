class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        //used spaces;
        vector<int> left(n,0);
        vector<int> right(n,0);
        stack<int> s;

        //right smaller
        for(int i=n-1;i>=0;i--){
            while(s.size()>0 && h[s.top()]>=h[i]){
                s.pop();
            }

            right[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        while(!s.empty()){s.pop();}     //empty satck

        //left smaller
        for(int i=0;i<n;i++){
            while(s.size()>0 && h[s.top()]>=h[i]){
                s.pop();
            }

            left[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        //final comparision of area
        int ans = 0;
        for(int i=0;i<n;i++){
            int currarea = h[i] * (right[i]-left[i]-1);
            ans = max(ans,currarea);
        }
        return ans;
    }
};
