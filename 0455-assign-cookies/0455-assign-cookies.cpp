class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int n = g.size(), m = s.size();
        vector<int> taken(m,0);
        for(int i=0;i<n;i++){
            int greed = g[i];
            int j;
            for(j=0;j<m;j++){
                if(!taken[j] && s[j]>=greed){
                    taken[j] = 1;
                    break;
                }
            }
            if(j==m)    return i;
        }
        return n;
    }
};