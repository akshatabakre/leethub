#define ll long long
class Solution {
public:
    ll minswaps(vector<int>& seq,int start){
        ll count = 0;
        for(int i=0;i<seq.size();i++){
            count += abs(seq[i] - (start + 2*i));
        }
        return count;
    }
    int minSwaps(vector<int>& nums) {
        vector<int> even, odd;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]%2){
                odd.push_back(i);
            }else{
                even.push_back(i);
            }
        }
        int ec = even.size(), oc = odd.size();
        if(abs(ec-oc)>1){
            return -1;
        }
        ll ans = LLONG_MAX;
        if(oc>=ec){
            ans = min(ans,minswaps(odd,0));
        }
        if(ec>=oc){
            ans = min(ans,minswaps(even,0));
        }
        return (int)ans;
    }
};