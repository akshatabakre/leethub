class Solution {
public:
    int minRotations(int n, string s){
        vector<int> v(n);
        //running sum + transition from s[i-1] to s[n-1] + add rev[i]
        //rev[i] = running sum from back

        reverse(s.begin(),s.end());
        s+='0';
        reverse(s.begin(),s.end());

        vector<int> suffsum(n+1,0);
        for(int i=n-1;i>=0;i--){
            int x = int(s[i]-'0'), y = int(s[i+1]-'0');
            if(x<y) swap(x,y);
            suffsum[i] = min(x-y,10+y-x);
        }
        for(int i=n-2;i>=0;i--){
            suffsum[i] += suffsum[i+1];
        }


        int prefsum = 0;
        int ans = 1e9;
        for(int i=1;i<=n;i++){
            int x = int(s[i-1]-'0'), y = int(s[i]-'0');
            int a = int(s[n]-'0'), b = int(s[i-1]-'0');
            if(a<b) swap(a,b);
            int tr = prefsum + min(a-b,10+b-a);
            tr += suffsum[i];
            ans = min(tr,ans);
            
            if(x<y) swap(x,y);
            prefsum += min(x-y,10+y-x);
        }

        return ans;
    }
};