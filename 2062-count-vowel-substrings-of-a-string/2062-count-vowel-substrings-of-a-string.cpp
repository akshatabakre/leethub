class Solution {
public:
    int countVowelSubstrings(string s) {
        int n = s.length();
        int cons = -1;
        int a=-1,e=-1,i=-1,o=-1,u=-1;
        int ans = 0;
        for(int ind=0;ind<n;ind++){
            if(s[ind]=='a')   a = ind;
            else if(s[ind]=='e')   e = ind;
            else if(s[ind]=='i')   i = ind;
            else if(s[ind]=='o')   o = ind;
            else if(s[ind]=='u')   u = ind;
            else                    cons = ind;
            if(a!=-1 && e!=-1 && i!=-1 && o!=-1 && u!=-1){
                int minind = min(a,min(e,min(i,min(o,u))));
                // cout<<ind<<" "<<minind-cons<<endl;
                ans += max(0,minind-cons);

            }
        }
        return ans;
    }
};