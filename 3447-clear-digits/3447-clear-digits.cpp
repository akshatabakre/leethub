class Solution {
public:
    string clearDigits(string s) {
        int n = s.length();
        vector<int> v(n);
        int d =0;
        for(int i=n-1;i>=0;i--){
            if(s[i]>='0' && s[i]<='9'){
                d++;
                v[i] = d;
            }else{
                v[i] = d;
                if(d>0) d--;
            }
        }
        string t = "";
        for(int i=0;i<n;i++){
            if(!v[i]){
                t+=s[i];
            }
        }
        return t;
    }
};