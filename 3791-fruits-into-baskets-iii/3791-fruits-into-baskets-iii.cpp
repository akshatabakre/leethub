class Solution {
public:
    int segTree[400001];
    vector<int> baskets;
    void build(int ind,int l,int r){
        if(l==r){
            segTree[ind] = baskets[l];
            return;
        }
        int mid = (l+r)>>1;
        build(ind<<1,l,mid);
        build(ind<<1|1,mid+1,r);
        segTree[ind] = max(segTree[ind<<1],segTree[ind<<1|1]);
    }
    void update(int ind,int l,int r,int pos,int val){
        if(pos<l||pos>r){
            return;
        }
        if(l==r){
            segTree[ind] = val;
            return;
        }
        int mid = (l+r)>>1;
        update(ind<<1,l,mid,pos,val);
        update(ind<<1|1,mid+1,r,pos,val);
        segTree[ind] = max(segTree[ind<<1],segTree[ind<<1|1]);
    }
    int query(int ind,int l,int r,int lq,int rq){
        if(r<lq || l>rq){
            return INT_MIN;
        }
        if(l>=lq && r<=rq){
            return segTree[ind];
        }
        int mid = (l+r)>>1;
        return max(query(ind<<1,l,mid,lq,rq),query(ind<<1|1,mid+1,r,lq,rq));
    }
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        this->baskets = baskets;
        int n = baskets.size();
        int cnt = 0;
        build(1,0,n-1);
        for(int i=0;i<n;i++){
            int q = fruits[i];
            int s = 0, e = n-1;
            int b = -1;
            if(n==0){
                return fruits.size();
            }
            while(s<=e){
                int mid = (s+e)>>1;
                if(query(1,0,n-1,0,mid)>=q){
                    b = mid;
                    e = mid-1;
                }else{
                    s = mid+1;
                }
            }
            if(b!=-1 && baskets[b]>=q){
                update(1,0,n-1,b,INT_MIN);
            }else{
                cnt++;
            }
        }
        return cnt;
    }
};