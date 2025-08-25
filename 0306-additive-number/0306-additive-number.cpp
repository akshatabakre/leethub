class Solution {
public:
    bool ans = false;
    void solve(string num,string curr,int i, vector<long long>& v){
        #define int long long
        //curr = "", curr = "12"
        if(i==num.size()){
            if(v.size()<2){
                return;
            }
            int n = v.size();
            if(n==2 && curr==""){
                return;
            }else if(n==2 && curr!=""){
                if(stoll(curr)==(long long)(v[n-1]+v[n-2])){
                    ans = true;
                }
                return;
            }
            if(curr=="" || stoll(curr)==(long long)(v[n-1]+v[n-2])){
                ans = true;
            }
            return;
        }
        int n = v.size();

        curr+=num[i];
        if(curr.size()>18){
            return;
        }
        if(curr!="0")
            solve(num,curr,i+1,v);
        if(v.size()<2){
            v.push_back(stoll(curr));
            solve(num,"",i+1,v);
            v.pop_back();
        }else if(stoll(curr)>(long long)(v[n-1]+v[n-2])){
            return;
        }else if(stoll(curr)==(long long)(v[n-1]+v[n-2])){
            v.push_back(stoll(curr));
            solve(num,"",i+1,v);
            v.pop_back();
        }
        #undef int
    }
    bool isAdditiveNumber(string num) {
        vector<long long> v;
        solve(num,"",0,v);
        return ans;
    }
};