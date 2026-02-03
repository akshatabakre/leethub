class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        // if(n<=3){
        //     return false;
        // }
        for(int p=1;p<n-1;p++){
            for(int q=p+1;q<n-1;q++){
                bool flag = true;
                for(int k=1;k<=p;k++){
                    if(nums[k]<=nums[k-1]){
                        flag = false;
                        break;
                    }
                }
                if(flag==false){
                    continue;
                }
                for(int k=p+1;k<=q;k++){
                    if(nums[k]>=nums[k-1]){
                        flag = false;
                        break;
                    }
                }
                if(flag==false){
                    continue;
                }
                for(int k=q+1;k<n;k++){
                    if(nums[k]<=nums[k-1]){
                        flag = false;
                        break;
                    }
                }
                if(flag==false){
                    continue;
                }
                // cout<<p<<q<<endl;
                return true;
            }
        }
        return false;
    }
};