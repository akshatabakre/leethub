class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> hor(m,0), ver(n,0);
        map<int,pair<int,int>> ind;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                pair<int,int> p;
                p.first = i, p.second = j;
                ind[mat[i][j]] = p;
            }
        }
        int i;
        for(i=0;i<m*n;i++){
            pair<int,int> p = ind[arr[i]];
            hor[p.first]++;
            ver[p.second]++;
            if(hor[p.first]==n || ver[p.second]==m){
                break;
            }
        }
        return i;
    }
};