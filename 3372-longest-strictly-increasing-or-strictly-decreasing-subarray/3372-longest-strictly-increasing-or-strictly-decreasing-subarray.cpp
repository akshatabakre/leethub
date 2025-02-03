class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ld, li,n=nums.size();
        int a,b;
        ld=li=0;
        a=b=1;
        for(int i=1;i<n;i++){
            if(nums[i]<nums[i-1]){
                a++;
            }else{
                ld = max(a,ld);
                a=1;
            }
            if(nums[i]>nums[i-1]){
                b++;
            }else{
                li = max(b,li);
                b=1;
            }
        }
        li = max(b,li), ld = max(a,ld);
        // cout<<li<<" "<<ld<<endl;
        return max(li,ld);
    }
};