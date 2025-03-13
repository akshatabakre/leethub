class Solution {
public:
    bool check(vector<int>& nums,vector<vector<int>>& q,int mid){
        // cout<<mid<<endl;
        vector<int> v(nums.size(),0);
        for(int i=0;i<=mid;i++){
            v[q[i][0]]-=q[i][2];
            if(q[i][1]+1<nums.size()){
                v[q[i][1]+1]+=q[i][2];
            }
        }
        for(int i=1;i<v.size();i++){
            v[i]+=v[i-1];
        }
        // for(int i=0;i<v.size();i++)    cout<<v[i]<<" ";
        cout<<endl;
        for(int i=0;i<nums.size();i++){
            if(nums[i]+v[i]>0){
                // cout<<mid<<" "<<i<<endl;
                return false;
            }
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), q = queries.size();
        int s = 0, e = q-1;
        bool alreadyzero = true;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){  
                alreadyzero = false;
                break;
            }
        }
        if(alreadyzero)     return 0;
        int ans = -1;
        while(s<=e){
            int mid = s + (e-s)/2;
            if(check(nums,queries,mid)){
                // cout<<"ans mid"<<endl;
                ans = mid+1;
                e = mid-1;
            }else{
                s = mid+1;
            }
        }
        return ans;
    }
};