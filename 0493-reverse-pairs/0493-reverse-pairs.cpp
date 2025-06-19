class Solution {
public:
    void merge(vector<int>& nums,int s,int mid,int e){
        vector<int> temp;
        int i = s, j = mid+1;
        while(i<=mid && j<=e){
            if(nums[i]<=nums[j]){
                temp.push_back(nums[i]);
                i++;
            }else{
                temp.push_back(nums[j]);
                j++;
            }
        }
        while(i<=mid){
            temp.push_back(nums[i++]);
        }
        while(j<=e){
            temp.push_back(nums[j++]);
        }
        for(int i=s;i<=e;i++){
            nums[i] = temp[i-s];
        }
        return;
    }
    int countPairs(vector<int>& nums,int s,int mid,int e){
        int cnt = 0;
        int j = mid+1;
        for(int i=s;i<=mid;i++){
            while(j<=e && nums[i]>2LL*nums[j])    j++;
            cnt += (j - (mid+1));
        }
        return cnt;
    }
    int mergesort(vector<int>& nums,int s,int e){
        if(s<e){
            int mid = s + (e-s)/2;
            int cnt = 0;
            cnt += mergesort(nums,s,mid);
            cnt += mergesort(nums,mid+1,e);
            cnt += countPairs(nums,s,mid,e);
            merge(nums,s,mid,e);
            return cnt;
        }
        return 0;
    }
    int reversePairs(vector<int>& nums) {
        return mergesort(nums,0,nums.size()-1);
    }
};