class Solution {
public:
    void nextPermutation(vector<int>& a) {
        //find pivot
        int pivot = -1, n=a.size();

        for(int i=n-2;i>=0;i--){
            if(a[i]<a[i+1]){
                pivot = i;
                break;
            }
        }
        if(pivot==-1) {reverse(a.begin(),a.end());
            return;}

        //next element
        for(int i=n-1;i>pivot;i--){
            if(a[i]>a[pivot]){
                swap(a[i],a[pivot]);
                break;
            }
        }

        reverse(a.begin() + pivot + 1,a.end());
        return;
    }
};
