class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int cnt = 0;
        int i=0;
        int n= nums.size();
        while(i<n){
            int x = nums[i];
            i++;
            while(i<n && x==nums[i]){
                i++;
            }
            if(i<n){
                cnt+=2;
                i++;
            }
        }
        return (n-cnt);
    }
};