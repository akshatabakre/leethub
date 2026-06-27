class Solution {
public:
    int trap(vector<int>& height) {
        //2 POINTERS
        #define int long long
        int n = height.size();
        int l=0,r=n-1;
        int water = 0;
        int lm = 0, rm = 0;
        while(l<=r){
            if(lm<=rm){
                    lm=max(lm,1LL*height[l]);
                    water += (lm-height[l]);
                
                l++;
            }else{
                    rm=max(rm,1LL*height[r]);
                    water+=(rm-height[r]);
                
              
                r--;
            }
        }
        return water;
        #undef int
    }
};