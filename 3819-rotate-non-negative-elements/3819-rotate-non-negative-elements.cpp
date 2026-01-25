class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        int n = nums.size();
        queue<int> q;
        for(int i=0;i<n;i++){
            if(nums[i]>=0){
                q.push(nums[i]);
            }
        }
        if(q.empty())   return nums;
        k = k%(q.size());
        cout<<k<<endl;
        while(k>0){
            q.push(q.front());
            q.pop();
            k--;
        }
        for(int i=0;i<n;i++){
            if(nums[i]>=0){
                nums[i] = q.front();
                q.pop();
            }
        }
        return nums;
    }
};