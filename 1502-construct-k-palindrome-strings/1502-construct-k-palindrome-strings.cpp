class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.length();
        int minpals = 0;
        map<char,int> f;
        for(int i=0;i<n;i++){
            f[s[i]]++;
        }
        for(auto i:f){
            if(i.second==1){
                minpals++;
            }else if(i.second%2==1){
                minpals++;
            }
        }
        if(minpals==0 && s.length()>0){
            minpals=1;
        }
        if(k>=minpals && k<=s.length()){
            return true;
        }
        return false;
    }
};