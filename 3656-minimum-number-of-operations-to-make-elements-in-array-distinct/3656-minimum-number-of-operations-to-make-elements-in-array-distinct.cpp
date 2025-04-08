class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int,int> count;
        int n = nums.size();
        int ind = n-1;
        for(ind;ind>=0;ind--){
            if(count[nums[ind]]==1){
                break;
            }else{
                count[nums[ind]]++;
            }
        }
        // cout<<ind<<" "<<count[nums[0]]<<endl;
        if(ind==-1){
            return 0;
        }
        return (ind/3)+1;
    }
};