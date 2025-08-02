class Solution {
public:
    int earliestFinishTime(vector<int>& lst, vector<int>& ld, vector<int>& wst, vector<int>& wd) {
        int n = lst.size(), m = wst.size();
        int ans = 1e9;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int s1 = lst[i], s2 = wst[j], d1 = ld[i], d2 = wd[j];
                ans = min(ans,min(max(s1+d1,s2)+d2,max(s2+d2,s1)+d1));
            }
        }
        return ans;
    }
};