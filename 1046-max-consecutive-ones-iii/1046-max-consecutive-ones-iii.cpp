class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int head = -1, tail = 0, n = nums.size();
        int cnt0 = 0;
        int ans = 0;
        while(tail < n){
            //take head to position
            while(head+1<n && cnt0 + (1-nums[head+1]) <= k){
                head++;
                cnt0 += (1-nums[head]);
            }
            cout<<tail<<" "<<head<<endl;
            //update ans
            ans = max(ans,head-tail+1);
            //increment tail
            if(head<tail){
                //empty window
                tail++;
                head = tail - 1;
            }else{
                if(!nums[tail]){
                    cnt0--;
                    tail++;
                }else{
                    tail++;
                }
            }
        }
            return ans;
    }
};