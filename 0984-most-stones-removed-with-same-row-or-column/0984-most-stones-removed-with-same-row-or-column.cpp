class DS{
    public:
    vector<int> parent,size;
    DS(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++)   parent[i] = i;
    }
    int findparent(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node] = findparent(parent[node]);
    }
    void unionbysize(int u,int v){
        int pu = findparent(u);
        int pv = findparent(v);
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
    int removeStones(vector<vector<int>>& stones) {
        int maxr = 0, maxc = 0;
        int s = stones.size();
        for(auto i:stones){
            maxr = max(i[0],maxr);
            maxc = max(i[1],maxc);
        }
        DS ds(maxr+maxc+1);
        for(auto i:stones){
            int noderow = i[0], nodecol = i[1]+maxr+1;
            ds.unionbysize(noderow,nodecol);
        }
        int nc = 0;
        for(int i=0;i<maxr+maxc+1;i++){
            if(ds.size[ds.findparent(i)]>1 && i==ds.findparent(i)){
                nc++;
            }
        }
        return (s-nc);
    }
};