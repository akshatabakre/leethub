class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        sort(s1.begin(),s1.end());
        if(s2.length()>=s1.length()){
            for(int i=0;i<s2.length()-s1.length()+1;i++){
                string subs = s2.substr(i,s1.length());
                // cout<<subs<<endl;
                sort(subs.begin(),subs.end());
                if(subs==s1){
                    return true;
                }
            }
        }else{
            return false;
        }
        return false;
    }
};