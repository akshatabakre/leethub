class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n = dimensions.size();
        int area = 0;
        double maxdiag = 0;
        for(int i=0;i<n;i++){
            double diag = sqrt(dimensions[i][0]*dimensions[i][0] + dimensions[i][1]*dimensions[i][1]);
            if(maxdiag < diag){
                maxdiag = diag;
                area = dimensions[i][0]*dimensions[i][1];
            }else if(maxdiag==diag){
                area = max(area,dimensions[i][0]*dimensions[i][1]);
            }
        }
        return area;
    }
};