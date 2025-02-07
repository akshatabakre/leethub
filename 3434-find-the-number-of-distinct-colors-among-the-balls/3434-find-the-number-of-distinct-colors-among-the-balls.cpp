class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& q) {
        int n = q.size();
        map<int,int> ctob, btoc;
        vector<int> ans(n,0) ;
        for(int i=0;i<n;i++){
            if(btoc.find(q[i][0])!=btoc.end()){
                ctob[btoc[q[i][0]]]--;
                if(ctob[btoc[q[i][0]]]==0){
                    ctob.erase(btoc[q[i][0]]);
                }
            }
            btoc[q[i][0]]=q[i][1];
            ctob[q[i][1]]++;
            ans[i] = min(btoc.size(),ctob.size());
        }
        
        return ans;
    }
};