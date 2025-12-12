class DSU{
    vector<int> parent;
    vector<int> size;
    public:
    DSU(int n){
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
        size.resize(n+1,1);
    }
    int findparent(int x){
        if(parent[x]==x){
            return x;
        }
        return parent[x] = findparent(parent[x]);
    }
    void unionbysize(int u,int v){
        int pu = findparent(u), pv = findparent(v);
        if(pu==pv){
            return;
        }
        if(size[pu]<size[pv]){
            parent[pu] = pv;
            size[pv]+=size[pu];
        }else{
            parent[pv] = pu;
            size[pu]+=size[pv];
        }
    }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>> edg;
        int n = points.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                edg.push_back({abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]),i,j});
            }
        }
        DSU dsu(n);
        sort(edg.begin(),edg.end());
        int mincost = 0;
        for(auto it:edg){
            int i = it[1],j=it[2];
            if(dsu.findparent(i)!=dsu.findparent(j)){
                mincost += it[0];
                dsu.unionbysize(i,j);
            }
        }
        return mincost;
    }
};