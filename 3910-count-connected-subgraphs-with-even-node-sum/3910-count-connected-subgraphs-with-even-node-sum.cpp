class Solution {
public:
    vector<vector<int>> allsub;
    vector<int> temp;
    vector<int> v;
    void rec(int i){
        if(i==v.size()){
            allsub.push_back(temp);
            return;
        }
        temp.push_back(v[i]);
        rec(i+1);
        temp.pop_back();
        rec(i+1);
    }

    void dfs(int node,int& cnt,vector<int>&vis,vector<vector<int>>&adj){
        vis[node] = 1;
        cnt++;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,cnt,vis,adj);
            }
        }
    }
    int evenSumSubgraphs(vector<int>& nums, vector<vector<int>>& edges) {
        int cnt = 0;

        //subset
        
        int n = nums.size();
        v.resize(n);
        for(int i=0;i<n;i++)    v[i] = i;

        rec(0);
        //adj

        for(int i=0;i<allsub.size();i++){
            set<int> s;
            for(int j=0;j<allsub[i].size();j++){
                s.insert(allsub[i][j]);
            }
            if(s.empty()){
                continue;
            }
            vector<vector<int>> adj(n);
            for(auto it:edges){
                if(s.find(it[0])!=s.end() && s.find(it[1])!=s.end()){
                    adj[it[0]].push_back(it[1]);
                    adj[it[1]].push_back(it[0]);
                }
            }
            int nodes = 0;
            vector<int> vis(n,0);
            dfs(*s.begin(),nodes,vis,adj);

            int sum = 0;
            for(int i:s){
                sum+=nums[i];
            }
            if(nodes==s.size() && sum%2==0){
                cnt++;
            }
        }
        return cnt;

    }
};