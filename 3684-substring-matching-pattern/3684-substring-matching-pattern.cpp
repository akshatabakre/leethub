class Solution {
public:
    bool hasMatch(string s, string p) {
        int n = s.length();
        int ind = p.find('*');
        string s1 = p.substr(0,ind);
        string s2 = p.substr(ind+1);
        if(s1.length()==0){
            if(s.find(s2)==string::npos){
                return false;
            }
            return true;
        }
        if(s2.length()==0){
            if(s.find(s1)==string::npos){
                return false;
            }
            return true;
        }
        reverse(s2.begin(),s2.end());
        string t = s;
        reverse(t.begin(),t.end());
        int ind1 = s.find(s1), ind2 = t.find(s2);
        if(ind2!=string::npos){
            ind2 += s2.length()-1;
            ind2 = n - ind2 -1;
        }
        if(ind1==string::npos || ind2==string::npos)    return false;
        if(ind2>=ind1+s1.length()){
            return true;
        }
        return false;
    }
};