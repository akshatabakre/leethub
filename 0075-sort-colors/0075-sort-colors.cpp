class Solution {
public:
    void sortColors(vector<int>& nums) {
        //0 to low-1 --> 0
        //low to mid-1 --> 1
        //high to n-1 --> 2
        //mid to high-1 --> unsorted
        int n = nums.size();
        int low = 0, mid = 0, high = n-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[mid],nums[low]);
                mid++;
                low++;
            }else if(nums[mid]==1){
                mid++;
            }else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};