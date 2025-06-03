class disjointSet{
    public:
    vector<int> parent,size;
    disjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++)   parent[i] = i;
    }
    int findParent(int node){
        if(parent[node]==node)  return node;
        return parent[node] = findParent(parent[node]);
    }
    void unionBySize(int u,int v){
        int pu = findParent(u), pv = findParent(v);
        if(pu==pv)  return;
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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        disjointSet ds(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]){
                    ds.unionBySize(i,j);
                }
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            if(i==ds.parent[i]){
                ans++;
            }
        }
        return ans;
    }
};