class DS{
    vector<int> parent,size;
    public:
    DS(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++)   parent[i] = i;
    }
    int findparent(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findparent(parent[node]);
    }
    void unionbysize(int u,int v){
        int pu = findparent(u), pv = findparent(v);
        if(pu == pv){
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int v = accounts.size();
        DS ds(v);
        map<string,int> mp;
        for(int acc = 0; acc < accounts.size() ; acc++){
            for(int e = 1; e < accounts[acc].size(); e++){
                string email = accounts[acc][e];
                if(mp.find(email)==mp.end()){
                    mp[email] = acc;
                }else{
                    ds.unionbysize(acc,mp[email]);
                }
            }
        }
        vector<vector<string>> merge(v), ans;
        for(auto it:mp){
            string mail = it.first;
            int node = ds.findparent(it.second);
            merge[node].push_back(mail);
        }
        for(int i=0;i<v;i++){
            if(merge[i].size() > 0){
                sort(merge[i].begin(),merge[i].end());
                vector<string> temp;
                temp.push_back(accounts[i][0]);
                for(auto it:merge[i]){
                    temp.push_back(it);
                }
                ans.push_back(temp);
            }
        }
        return ans;
    }
};