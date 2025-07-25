class NumArray {
public:
    int n;
    vector<int> arr;
    vector<int> t;
    NumArray(vector<int>& nums) {
        n = nums.size();
        arr.resize(n);
        t.resize(4*n);
        arr = nums;
        build(1,0,n-1);
    }
    void build(int index,int l,int r){
        if(l==r){
            t[index] = arr[l];
            return;
        }
        int mid = l + (r-l)/2;
        build(2*index,l,mid);
        build(2*index + 1,mid+1,r);
        t[index] = t[2*index] + t[2*index + 1];
        return;
    }
    void UPDATE(int ind,int l, int r,int pos,int val){
        if(pos<l || pos>r){
            return;
        }
        if(l==r){
            t[ind] = val;
            arr[pos] = val;
            return;
        }
        int mid = l + (r-l)/2;
        UPDATE(ind*2,l,mid,pos,val);
        UPDATE(ind*2 + 1,mid+1,r,pos,val);
        t[ind] = t[2*ind] + t[2*ind + 1];
        return;
    }
    void update(int index, int val) {
        UPDATE(1,0,n-1,index,val);
    }

    int query(int ind,int l,int r,int lq,int rq){
        if(r<lq || l>rq){
            return 0;
        }
        if(l>=lq && r<=rq){
            return t[ind];
        }
        int mid = l + (r-l)/2;
        return query(2*ind,l,mid,lq,rq) + query(2*ind + 1,mid+1,r,lq,rq);
    }
    
    int sumRange(int left, int right) {
        return query(1,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */