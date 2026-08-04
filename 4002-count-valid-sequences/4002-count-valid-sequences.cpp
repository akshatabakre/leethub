class Solution {
public:
    long long mod = 1e9 + 7;

    long long binpow(long long b,long long e){
        if(e==0)    return 1;
        if(e%2){
            return (b*binpow(b,e-1))%mod;
        }
        long long temp = binpow(b,e/2);
        return (temp*temp)%mod;
    }

    long long modinv(long long x){
        return binpow(x,mod-2);
    }

    long long C(long long n,long long k){
        if (k<0 || k>n || n<0)
            return 0;
        k = min(k,n-k);
        long long ans = 1;
        for(int i=0;i<k;i++){
            ans = (ans*(n-i))%mod;
            ans = (ans*modinv(i+1))%mod;
        }
        return ans%mod;
    }
    int countValidSequences(int n, int k) {
        long long total = C(n-1,k-1);
        long long x = (n-k)/2;
        if((n-k)%2){
            return total;
        }
        long long bad = C(x+k-1,k-1);
        return (total-bad+mod)%mod;
    }
};