class Solution {
public:
    int maximumCount(vector<int>& nums) {
        //binary search to find the first occurence of number >0, and last occurence of number <0
        int i=-1,j=-1;
        int s = 0, e = nums.size()-1;
        int n = nums.size();
        while(s<=e){
            int mid = s + (e-s)/2;
            if(nums[mid]>=0){
                e = mid-1;
            }else{
                i = mid;
                s = mid+1;
            }
        }
        s = 0, e = n-1;
        while(s<=e){
            int mid = s + (e-s)/2;
            if(nums[mid]<=0){
                s = mid+1;
            }else{
                j = mid;
                e = mid-1;
            }
        }
        cout<<i<<" "<<j<<endl;
        if(i==-1 && j==-1){
            return 0;
        }
        else if(i==-1){
            return n-j;
        }
        else if(j==-1){
            return  i+1;
        }
        return max(i+1,n-j);
    }
};