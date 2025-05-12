#define ll long long
class Solution {
public:
    void addIntInVec(ll &num,vector<int>& digits,set<int>& ans,vector<int>&taken){
        if(num/100!=0 && num/1000==0){
            // cout<<num<<endl;
            if(num%2==0){
                ans.insert(num);
            }
            return;
        }

        for(int i=0;i<digits.size();i++){
            // cout<<i<<" "<<taken[i]<<endl;
            if((num!=0 || digits[i]!=0) && !taken[i]){
                num*=10;
                num+=digits[i];
                taken[i] = 1;
                addIntInVec(num,digits,ans,taken);
                taken[i] = 0;
                num/=10;
            }
        }
    }
    vector<int> findEvenNumbers(vector<int>& digits) {
        sort(digits.begin(),digits.end());
        int n = digits.size();
        vector<int> taken(n,0), ans;
        set<int> a;
        ll num = 0;
        addIntInVec(num,digits,a,taken);
        for(int nums:a){
            ans.push_back(nums);
        }
        return ans;
    }
};