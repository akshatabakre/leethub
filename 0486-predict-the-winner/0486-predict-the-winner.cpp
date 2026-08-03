class Solution {
public:

    vector<int> nums;

    int solve(int l,int r){
        if(l>r){
            return 0;
        }
        int maxi = -1e9;
        maxi = max(nums[l]-solve(l+1,r),maxi);
        maxi = max(nums[r]-solve(l,r-1),maxi);
        return maxi;
    }

    bool predictTheWinner(vector<int>& nums) {
        this->nums = nums;
        int x = solve(0,nums.size()-1);
        cout<<x<<endl;
        return (x>=0);
    }
};