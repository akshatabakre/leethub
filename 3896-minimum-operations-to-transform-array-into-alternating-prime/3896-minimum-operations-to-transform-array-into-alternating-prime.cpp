class Solution {
public:

    vector<long long> isPrime,primes;;

    void precompute(){
        isPrime.resize(1e5 + 1,1);
        isPrime[1] = 0;
        for(long long i=2;i<=1e5;i++){
            if(isPrime[i]){
                primes.push_back(i);
                for(long long j=i*i;j<=1e5;j+=i){
                    isPrime[j] = 0;
                }
            }
        }
        primes.push_back(100003);
        
    }
    int minOperations(vector<int>& nums) {
        long long ans = 0;
        long long n = nums.size();
        precompute();
        for(long long i=0;i<n;i++){
            if(i%2){
                if(isPrime[nums[i]]){
                    if(nums[i]==2){
                        ans+=2;
                    }else{
                        ans++;
                    }
                }
            }else{
                if(!isPrime[nums[i]]){
                    long long ind = lower_bound(primes.begin(),primes.end(),nums[i])-primes.begin();
                    if(ind<primes.size()){
                        ans += (primes[ind]-nums[i]);
                    }
                }
            }
            
        }
        return ans;
    }
};