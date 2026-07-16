class DSU{
    vector<int> parent,size;
    public:
    DSU(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }
    int findparent(int node){
        if(parent[node]==node){
            return node;
        }
        return parent[node] = findparent(parent[node]);
    }
    void unionn(int u,int v){
        int pu = findparent(u), pv = findparent(v);
        if(pu==pv){
            return;
        }
        if(size[pu]>size[pv]){
            parent[pv] = pu;
            size[pu]+=size[pv];
        }else{
            parent[pu] = pv;
            size[pv]+=size[pu];
        }
    }
};

class Solution {
public:
    int n;
    vector<vector<int>> points;

    int man(int i,int j){
        return abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
    }

    bool check(int mid){
        DSU dsu(2*n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                // if(dsu.findparent(i)==dsu.findparent(j)){
                //     if(man(i,j)<mid){
                //         return false;
                //     }
                // }else{
                //     if(man(i,j)>=mid){
                //         dsu.unionn(i,j);
                //     }
                // }
                if(man(i,j)<mid)
                {
                    dsu.unionn(i,j+n);
                    dsu.unionn(i+n,j);
                }
            }
        }
        // int comp = 0;
        // for(int i=0;i<n;i++){
        //     if(dsu.findparent(i)==i){
        //         comp++;
        //     }
        // }
        // if(comp<=2){
        //     return true;
        // }
        // return false;
        for(int i=0;i<n;i++){
            if(dsu.findparent(i)==dsu.findparent(i+n))
            return false;
        }
        return true;
    }
    
    int maxPartitionFactor(vector<vector<int>>& points) {
        this->points = points;
        n = points.size();
        if(n==2){
            return 0;
        }
        int s = 0, e = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                e = max(man(i,j),e);
            }
        }
        int ans = -1;
        while(s<=e){
            int mid = s + (e-s)/2;
            if(check(mid)){
                s = mid+1;
                ans = mid;

            }else{
                e = mid-1;
            }
        }
        return ans;
    }
};