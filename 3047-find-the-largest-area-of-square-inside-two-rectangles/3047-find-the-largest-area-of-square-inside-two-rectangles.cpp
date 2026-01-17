class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bl, vector<vector<int>>& tr) {
        int n = bl.size();
        int maxside = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int a = min(tr[i][0],tr[j][0]);
                int b = max(bl[i][0],bl[j][0]);
                int c = min(tr[i][1],tr[j][1]);
                int d = max(bl[i][1],bl[j][1]);
                int len = a-b, bre = c-d;
                maxside = max(maxside,min(len,bre));
            }
        }
        return 1LL*maxside*maxside;
    }
};