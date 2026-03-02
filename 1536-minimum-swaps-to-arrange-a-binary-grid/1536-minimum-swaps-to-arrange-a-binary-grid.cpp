class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> swaps(n);
        for(int i=0;i<n;i++){
            int one = -1;
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    one = j;
                }
            }
            swaps[i] = one;
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            if(swaps[i]>i){
                int j;
                for(j=i+1;j<n;j++){
                    if(swaps[j]<=i){
                        break;
                    }
                }
                if(j==n){
                    return -1;
                }
                ans += j-i;
                while(j-1>=i){
                    swap(swaps[j],swaps[j-1]);
                    j--;
                }
            }
        }
        return ans;
    }
};