class Solution {
public:
    vector<int> leftmax(vector<int>& h,int n){
        vector<int> lm(n);
        lm[0] = h[0];
        for(int i=1;i<n;i++){
            lm[i] = max(lm[i-1],h[i]);
        }
        return lm;
    }
    vector<int> rightmax(vector<int>& h,int n){
        vector<int> rm(n);
        rm[n-1] = h[n-1];
        for(int i=n-2;i>=0;i--){
            rm[i] = max(rm[i+1],h[i]);
        }
        return rm;
    }
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left = leftmax(height,n);
        vector<int> right = rightmax(height,n);
        int ans = 0;
        for(int i=0;i<n;i++){
            // if(left[i]!=-1 && right[i]!=n){
                ans+=(min(left[i],right[i])-height[i]);
            // }
        }
        return ans;
    }
};