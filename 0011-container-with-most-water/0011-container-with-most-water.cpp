class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxw = 0, n = height.size();
        int lp=0,rp=n-1;
        while(lp<rp){
            maxw = max(min(height[lp],height[rp])*(rp-lp),maxw);
            if(height[lp]<height[rp]){
                lp++;
            }else{
                rp--;
            }
        }
        return maxw;
    }
};