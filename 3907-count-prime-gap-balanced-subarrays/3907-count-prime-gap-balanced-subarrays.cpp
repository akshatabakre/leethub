class Solution {
public:
    vector<int> sieve(int n){
        vector<int> prime(n+1,1);
        prime[0] = prime[1] = 0;
        for(int i=2;i*i<=n;i++){
            if(prime[i]){
                for(int j=i*i;j<=n;j+=i){
                    prime[j] = 0;
                }
            }
        }
        return prime;
    }
    bool check(multiset<int>& m, vector<int>& nums, int r, int k,vector<int>& p) {
        return ((m.size() < 1) || (m.size() >= 1 && ((p[nums[r + 1]] == 0) ||
                (p[nums[r + 1]] == 1 && *m.rbegin() - nums[r + 1] <= k &&
                 nums[r + 1] - *m.begin() <= k))));
    }

    int primeSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = 0;
        for(int i:nums)     maxi = max(i,maxi);
        vector<int> isPrime = sieve(maxi);
        multiset<int> ms;
        deque<int> dq;
        int l = 0, rmin = -1, rmax = -1;
        int ans = 0;
        while(l<n){
            while(rmax+1<n && check(ms,nums,rmax,k,isPrime)){
                rmax++;
                if(isPrime[nums[rmax]]){
                    ms.insert(nums[rmax]);
                    dq.push_back(rmax);
                    if(ms.size()==2){
                        rmin = rmax;
                    }
                }
            }
            if(ms.size()>=2 && rmin!=-1){
                rmin = dq[1];
                ans += (rmax-rmin+1);
            }
            
            if(rmax<l){
                l++;
                rmax = l-1;
            }else{
                if(isPrime[nums[l]]){
                    ms.erase(ms.find(nums[l]));
                    if(!dq.empty() && dq.front()==l)
                        dq.pop_front();
                    if(ms.size()<2){
                        rmin = -1;
                    }else{
                        rmin = dq[1];
                    }
                }
                l++;
            }
        }
        return ans;
    }
};