class Solution {
public:
    vector<long long> prime;
    void getPrimes(long long n){
        prime.resize(n+1,1);
        prime[1] = 0;
        for(long long i=2;i<=n;i++){
            if(!prime[i])   continue;
            for(long long j=i*i;j<=n;j+=i){
                prime[j] = 0;
            }
        }
    }
    vector<int> maxPrimes(int n, int s) {
        vector<int> ans;
        getPrimes(n);
        int sum = 0;
        for(int i=1;i<=n;i++){
            if(prime[i]){
                if(sum+i>s)   break; 
                sum+=i;
                ans.push_back(i);
            }
        }
        return ans;
    }
};