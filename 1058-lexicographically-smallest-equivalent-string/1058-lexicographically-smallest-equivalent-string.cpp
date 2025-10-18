class DSU{
    public:
    vector<int> parent;
    DSU(){
        parent.resize(26);
        for(int i=0;i<26;i++){
            parent[i] = i;
        }
    }
    int findparent(int x){
        if(parent[x]==x){
            return x;
        }
        return parent[x] = findparent(parent[x]);
    }
    void unionByLex(int u,int v){
        int pu = findparent(u);
        int pv = findparent(v);
        if(pu==pv){
            return;
        }
        if(pu<pv){
            parent[pv] = pu;
        }else{
            parent[pu] = pv;
        }
    }
};
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        DSU dsu;
        int n = s1.length();
        for(int i=0;i<n;i++){
            dsu.unionByLex(s1[i]-'a',s2[i]-'a');
        }
        string ans = "";
        for(char ch : baseStr){
            ans += char('a'+ dsu.findparent(ch-'a'));
        }
        return ans;
    }
};