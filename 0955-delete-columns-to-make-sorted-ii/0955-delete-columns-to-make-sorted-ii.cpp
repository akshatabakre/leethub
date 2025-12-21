class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        vector<int> del(m,false), sor(n,false);
        for(int i=0;i<m;i++){
            vector<int> tsor(n,false);
            for(int j=0;j<n;j++){
                tsor[j] = sor[j];
            }
            for(int j=1;j<n;j++){
                if(!tsor[j-1] && strs[j][i]<strs[j-1][i]){
                    del[i] = true;
                }else if(strs[j][i]>strs[j-1][i]){
                    tsor[j-1] = true;
                }
            }
            if(!del[i]){
                for(int j=0;j<n;j++){
                    sor[j] = tsor[j];
                }
            }
        }
        int ans = 0;
        for(int i=0;i<m;i++){
            if(del[i]){
                ans++;
                cout<<i<<" ";
            }
        }
        return ans;
    }
};