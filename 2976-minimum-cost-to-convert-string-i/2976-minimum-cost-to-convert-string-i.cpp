class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        #define int long long
        int n = source.length();
        int m = original.size();
        vector<vector<int>> mincost(26,vector<int>(26,1e15));
        vector<vector<vector<int>>> adj(26);
        for(int i=0;i<m;i++){
            adj[original[i]-'a'].push_back({changed[i],cost[i]});
        }
        for(int i=0;i<26;i++)   mincost[i][i] = 0;
        for(int i=0;i<m;i++){
            mincost[original[i]-'a'][changed[i]-'a'] = min((long long)cost[i],mincost[original[i]-'a'][changed[i]-'a']);
        }
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                for(int k=0;k<26;k++){
                    if(mincost[j][i]==1e15||mincost[i][k]==1e15)  continue;
                    mincost[j][k] = min(mincost[j][i]+mincost[i][k],mincost[j][k]);
                }
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            if(source[i]==target[i])    continue;
            if(mincost[source[i]-'a'][target[i]-'a']==1e15){
                return -1;
            }
            ans += mincost[source[i]-'a'][target[i]-'a'];
        }
        return ans;
        #undef int
    }
};