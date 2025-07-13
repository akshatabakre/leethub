class DS{
    vector<int> parent;
    vector<int> size;
    public:
    DS(int n){
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
        size.resize(n+1,1);
    }
    int findparent(int node){
        if(parent[node]==node){
            return node;
        }
        return parent[node] = findparent(parent[node]);
    }
    void UNION(int u,int v){
        int pu = findparent(u);
        int pv = findparent(v);
        if(pu==pv){
            return;
        }
        if(size[pu]<size[pv]){
            parent[pu] = pv;
            size[pv] += size[pu];
        }else{
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};
class Solution {
public:
    static bool cmp(vector<int>& a,vector<int>& b){
        if(a[2]==b[2]){
            if(a[0]==b[0]){
                return a[1]<b[1];
            }
            return a[0]<b[0];
        }
        return a[2]<b[2];
    }
    int minCost(int n, vector<vector<int>>& edges, int k) {
        sort(edges.begin(),edges.end(),cmp);
        int nc = n;
        int maxi = 0;
        for(auto it:edges){
            cout<<it[2]<<endl;
        }
        DS ds(n);
        for(auto it:edges){
            if(nc<=k){
                return maxi;
            }
            if(ds.findparent(it[0])!=ds.findparent(it[1])){
                ds.UNION(it[0],it[1]);
                nc--;
                maxi = max(it[2],maxi);
            }
        }
        return maxi;
    }
};