class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> v(n,1);//i=0 base case
        //all of the first row cells will have one path to go to 0,0
        for(int i=1;i<m;i++){
            vector<int> temp(n,0);
            for(int j=0;j<n;j++){
                int up = v[j], left = 0;
                if(j>0) left = temp[j-1];
                temp[j] = up+left;
            }
            v = temp;
        }
        return v[n-1];
    }
};