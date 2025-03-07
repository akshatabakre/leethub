class Solution {
public:
    vector<int> primes(int n){vector<int>v(n+1,1);v[0]=v[1]=0;for(int i=2;i*i<=n;i++)if(v[i])for(int j=i*i;j<=n;j+=i)v[j]=0;return v;}
    vector<int> getprime(int n){vector<int>v,b=primes(n);for(int i=2;i<=n;i++)if(b[i])v.push_back(i);return v;}
    vector<int> closestPrimes(int left, int right) {
        vector<int> p = getprime(right);
        vector<int> ans(2,-1);
        if(p.empty()){
            return ans;
        }
        int mindiff = INT_MAX;
        int ind = 0;
        while(ind<p.size() && p[ind]<left){
            ind++;
        }
        if(ind>=p.size()-1){
            return ans;
        }
        for(int i=ind;i<p.size()-1;i++){
            if(p[i+1]-p[i]<mindiff){
                ans[0] = p[i],ans[1] = p[i+1];
                mindiff = p[i+1]-p[i];
            }
        }
        return ans;
    }
};