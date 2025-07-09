#define ll long long
class Solution {
public:
    void emptyStack(stack<pair<int,int>>& s){
        while(!s.empty()){
            s.pop();
        }
    }
    void buildMin(int n,vector<int>& v1,vector<int>& v2,vector<int>& nums,stack<pair<int,int>>& s){
        emptyStack(s);
        for(int i=0;i<n;i++){
            while(!s.empty() && s.top().first>=nums[i]){
                s.pop();
            }
            if(!s.empty()){
                v1[i] = s.top().second;
            }
            s.push({nums[i],i});
        }

        emptyStack(s);
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && s.top().first>nums[i]){
                s.pop();
            }
            if(!s.empty()){
                v2[i] = s.top().second;
            }
            s.push({nums[i],i});
        }
    }
    void buildMax(int n,vector<int>& v1,vector<int>& v2,vector<int>& nums,stack<pair<int,int>>& s){
        emptyStack(s);
        for(int i=0;i<n;i++){
            while(!s.empty() && s.top().first<=nums[i]){
                s.pop();
            }
            if(!s.empty()){
                v1[i] = s.top().second;
            }
            s.push({nums[i],i});
        }
        emptyStack(s);
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && s.top().first<nums[i]){
                s.pop();
            }
            if(!s.empty()){
                v2[i] = s.top().second;
            }
            s.push({nums[i],i});
        }
    }
    long long subArrayRanges(vector<int>& nums) {
        long long ans = 0;
        ll n = nums.size();
        vector<int> leftmin(n,-1),rightmin(n,n), leftmax(n,-1),rightmax(n,n);
        stack<pair<int,int>> s;
        buildMin(n,leftmin,rightmin,nums,s);
        buildMax(n,leftmax,rightmax,nums,s);

        for(int i=0;i<n;i++){
            // ans = (ans+(ll)nums[i]*(((rightmax[i]-i)*(i-leftmax[i]))-((rightmin[i]-i)*(i-leftmin[i]))));
            ll maxi = (ll)(i - leftmax[i]) * (rightmax[i] - i);
            ll mini = (ll)(i - leftmin[i]) * (rightmin[i] - i);
            ans += (ll)nums[i] * (maxi - mini);
        }
        return ans;
    }
};