#define ll long long
class Solution {
public:
    bool check(vector<int>& ranks,ll mid, int cars){
        ll count = 0;
        for(ll i:ranks){
            ll y = mid/i;
            ll x = sqrtl(y);
            count+=x;
        }
        return (count>=cars);
    }
    long long repairCars(vector<int>& ranks, int cars) {
        ll lo = 1, hi = 0;
        hi = 1LL * ranks[0] * cars * cars;
        for (ll i : ranks) {
            hi = min(hi, 1LL * i * cars * cars);
        }

        long long ans = 0;
        while(lo<=hi){
            ll mid = lo + (hi-lo)/2;
            if(check(ranks,mid,cars)){
                ans = mid;
                hi = mid-1;
            }else{
                lo = mid+1;
            }
        }
        return ans;
    }
};