class Solution {
public:
    string removeDigit(string number, char digit) {
        vector<string> v;
        for(int i=0;i<number.length();i++){
            if(number[i]==digit){
                string dup = number;
                dup.erase(i,1);
                v.push_back(dup);
            }
        }
        string maxi = "";
        for(int i=0;i<v.size();i++){
            maxi = max(maxi,v[i]);
        }
        return maxi;
    }
};