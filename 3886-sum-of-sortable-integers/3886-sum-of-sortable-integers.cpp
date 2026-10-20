class Solution {
public:
    vector<int> prefix;
    int check(vector<int>&nums,int d){
        int prevmax = -1e9;
        for(int l=0;l<nums.size();l+=d){
            int r = l+d-1;
            int currmin = 1e9;
            for(int i=l;i<=r;i++){
                currmin = min(nums[i],currmin);
            }
            if(currmin>=prevmax && (prefix[l]==prefix[r] || (prefix[l]==prefix[r]-1 && nums[r]<=nums[l]))){
                
            }else{
                return 0;
            }

            prevmax = 0;
            for(int i=l;i<=r;i++){
                prevmax = max(prevmax,nums[i]);
            }
        }
        return d;
    }
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();

        prefix=vector<int>(n);
        prefix[0] = 0;
        for(int i=1;i<n;i++){
            if(nums[i]<nums[i-1]){
                prefix[i] = prefix[i-1]+1;
            }else{
                prefix[i] = prefix[i-1];
            }
        }
        int ans = 0;
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                ans += check(nums,i);
                if(i != n/i){
                    ans += check(nums,n/i);
                }
            }
        }

        return ans;
    }
};