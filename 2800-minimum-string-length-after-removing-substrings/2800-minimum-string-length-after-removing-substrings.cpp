class Solution {
public:
    int minLength(string s) {
        bool stillleft = true;
        while(stillleft){
            stillleft = false;
            int ind = s.find("AB");
            if(ind!=string::npos){
                s.erase(ind,2);
                stillleft = true;
            }
            ind = s.find("CD");
            if(ind!=string::npos){
                s.erase(ind,2);
                stillleft = true;
            }
        }
        return s.length();
    }
};