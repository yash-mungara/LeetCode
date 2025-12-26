class MinHeap{
public:
    vector<int> h;

    void push(int x){
        h.push_back(x);
        int i = h.size()-1;

        while(i>0){
            int p= (i-1)/2;
            if(h[p]<=h[i]) break;
            swap(h[p],h[i]);
            i=p;
        }
    }

    void pop(){
        swap(h[0],h.back());
        h.pop_back();

        int i=0, n=h.size();
        while(true){
            int l=2*i+1, r=2*i+2, smallest=i;

            if(l<n && h[l]<=h[smallest]) smallest = l;
            if(r<n && h[r]<=h[smallest]) smallest = r;

            if(smallest==i) break;
            swap(h[i],h[smallest]);
            i=smallest;
        }
    }

    int top(){
        return h[0];
    }

    int size(){
        return h.size();
    }
};
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        MinHeap heap;

        for(int x:nums){
            heap.push(x);
            if(heap.size()>k){
                heap.pop();
            }
        }
        return heap.top();
    }
};
