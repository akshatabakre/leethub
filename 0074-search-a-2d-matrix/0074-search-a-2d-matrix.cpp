class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //index = row*(n-1) + col
        //row = index/(n-1)
        //col = index%(n-1)
        int m = matrix.size(), n = matrix[0].size();
        int s = 0, e = m*n - 1;
        while(s<=e){
            int mid = s + (e-s)/2;
            int mr = mid/n, mc = mid%n;
            if(matrix[mr][mc]==target){
                return true;
            }
            if(matrix[mr][mc]<target){
                s = mid+1;
            }else{
                e = mid-1;
            }
        }
        return false;
    }
};