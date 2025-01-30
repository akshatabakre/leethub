class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> m(n,vector<int>(n));
        int top = 0, bottom = n-1, left = 0, right = n-1;
        int c = 1;
        while(top<=bottom && left<=right){
            //for top row
            for(int i=left;i<=right;i++){
                m[top][i] = c++;
            }
            top++;
            //right column
            for(int i=top;i<=bottom;i++){
                m[i][right] = c++;
            }
            right--;
            //bottom row
            if(top<=bottom){//checking after updation
                for(int i=right;i>=left;i--){
                    m[bottom][i] = c++;
                }
                bottom--;
            }
            //left column
            if(left<=right){
                for(int i=bottom;i>=top;i--){
                    m[i][left] = c++;
                }
                left++;
            }
        }
        return m;
    }
};