class Solution {
public:
    int shipWithinDays(vector<int>& arr, int days) {
        int n = arr.size();
        int st = *max_element(arr.begin(),arr.end());
        int mid, end=0, ans=st ;
        for(int i=0;i<n;i++){end+=arr[i];}
        while(st<=end){
            mid = st + (end-st)/2;
            int x= days;
            int i=0;
                while(i<n && x>0){
                    int  y = mid;
                    while(i<n && y>=0){
                    y = y-arr[i];
                    if(y>=0)i++;
                    }x--;
                }
            if(i == n) {
            ans = mid;
            end = mid - 1;
            } else {
               st = mid + 1;
            }
        }
        return ans;
    }
};
