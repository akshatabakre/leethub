class Solution {
public:
    void solve(vector<int>&v,int curr,int d){
        int n = v.size();
        while(curr>=0 && curr<n){
            if(v[curr]==0){
                if(d){
                    curr++;
                }else{
                    curr--;
                }
            }else{
                v[curr]--;
                d = !d;
                if(d){
                    curr++;
                }else{
                    curr--;
                }
            }
        }
    }
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int curr=0;curr<n;curr++){
            if(nums[curr]){
                continue;
            }
            for(int dir=0;dir<2;dir++){//0L,1R
                vector<int> v = nums;
                solve(v,curr,dir);
                bool allzero = true;
                for(int i=0;i<n;i++){
                    if(v[i]){
                        allzero = false;
                        break;
                    }
                }
                if(allzero){
                    ans++;
                    cout<<curr<<" "<<dir<<endl;
                }
            }
        }
        return ans;
    }
};