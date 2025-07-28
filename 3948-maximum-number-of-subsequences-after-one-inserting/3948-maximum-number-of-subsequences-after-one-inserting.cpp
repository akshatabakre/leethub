#define ll long long
class Solution {
public:
    long long numOfSubsequences(string s) {
        ll totalLCT = 0;
        ll L = 0, LC = 0;
        ll C = 0, CT = 0;
        ll T = 0;
        int n = s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='L'){
                L++;
            }else if(s[i]=='C'){
                LC += L;
                C++;
            }else if(s[i]=='T'){
                totalLCT += LC;
                CT+=C;
                T++;
            }
        }
        ll ans = 0;
        //if L is added at beginning
        ans = max(ans,totalLCT + CT);
        //if T at end
        ans = max(ans,totalLCT + LC);
        //if C somewhere in middle
        L = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='L'){
                L++;
            }else if(s[i]=='T'){
                T--;
            }
            ans = max(ans,totalLCT + (L*T));
        }
        return ans;
    }
};