class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int max = *max_element(arr.begin(),arr.end()), n=arr.size();
        if(max-n<k) return max+k-(max-n);
        if(arr.size()==1 && k<arr[0]) return k;
        if(arr.size()==1 && k>arr[0]) return k+1;
        int st = 0, end = n-1, mid;
        while(st<=end){
            mid = st+(end-st)/2;
            if(arr[mid]-mid-1<k) st=mid+1;
            else end = mid-1;
        }
        if(end<0) {
            end=0;
            return k;
        }
        return arr[end]+(k-(arr[end]-end-1));
    }
};
