class Solution {
public:
    int atmostk(vector<int>& nums, int k){
        int head = -1, tail = 0;
        int n = nums.size();
        int odds = 0, ans = 0;
        while(tail<n){
            while(head+1<n && odds + (nums[head+1]%2)<=k){
                head++;
                odds += (nums[head]%2);
            }
            // cout<<tail<<" "<<head<<endl;
            ans+=(head-tail+1);
            odds -= (nums[tail]%2);
            tail++;
            if(tail>head){
                head = tail-1;
                odds = 0;
            }
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmostk(nums,k) - atmostk(nums,k-1);
    }
};