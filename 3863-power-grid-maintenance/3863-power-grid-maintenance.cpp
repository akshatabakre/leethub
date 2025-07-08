class DS{
    public:
    vector<int> parent;
    vector<int> size;
    DS(int n){
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
    void unionBySize(int u,int v){
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
    vector<int> processQueries(int c, vector<vector<int>>& conn, vector<vector<int>>& queries) {
        map<int,bool> offline;
        unordered_map<int,int> stoc;
        DS ds(c);
        map<int,set<int>> mp;
        for(auto it:conn){
            ds.unionBySize(it[0],it[1]);
        }
        for(int i=1;i<=c;i++){
            int p = ds.findparent(i);
            mp[p].insert(i);
            stoc[i] = p;
        }
        int q = queries.size();
        vector<int> ans;
        for(int i=0;i<q;i++){
            int station = queries[i][1];
            int comp = stoc[station];
            if(queries[i][0]==1){
                if(offline[station]){
                    if(mp[comp].empty()){
                        ans.push_back(-1);
                    }else
                    ans.push_back(*(mp[comp].begin()));
                }else{
                    ans.push_back(station);
                }
            }else{
                offline[station] = true;
                mp[comp].erase(station);
            }
        }
        return ans;
    }
};