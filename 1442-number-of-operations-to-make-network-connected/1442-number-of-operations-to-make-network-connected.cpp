class DS{
    public:
    vector<int> parent,size;
    DS(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++)   parent[i] = i;
    }
    int findparent(int node){
        if(parent[node]==node)  return node;
        return parent[node] = findparent(parent[node]);
    }
    void unionbysize(int u,int v){
        int pu = findparent(u), pv = findparent(v);
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1)  return -1;
        DS ds(n);
        int extras = 0;
        for(auto i:connections){
            if(ds.findparent(i[0])==ds.findparent(i[1])){
                extras++;
            }
            else
                ds.unionbysize(i[0],i[1]);
        }
        int nc = 0;
        for(int i=0;i<n;i++){
            if(i==ds.parent[i]){
                nc++;
            }
        }
        // cout<<extras<<" "<<nc<<endl;
        if(extras<nc-1){
            return -1;
        }
        return nc-1;
    }
};