class Solution {
public:
    vector<int> lexSmallestNegatedPerm(int n, long long target) {
        // #define int long long
        long long sum = (long long)n*(n+1)/2;
        if(target>sum || target<-sum){
            // cout<<1<<endl;
            return {};
        }
        if(abs(target)%2!=sum%2){
            // cout<<2<<endl;
            return {};
        }
        vector<int> ans;
        for(int i=n;i>=1;i--){
            long long s = (long long)i*(i-1)/2;
            if(abs(target+i)%2!=(s%2) || (target+i)>s || target+i<-s){
                target-=i;
                ans.push_back(i);
                // cout<<i<<endl;
            }else{
                target+=i;
                ans.push_back(-i);
                // cout<<-i<<endl; 
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
        // #undef int
    }
};