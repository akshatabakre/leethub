class Solution {
public:
    bool isNum(char c){
        return (c>='0' & c<='9');
    }
    bool isAlpha(char c){
        return ((c>='a' && c<='z')||(c>='A' && c<='Z'));
    }
    bool isValid(string code){
        if(code.length()==0){
            return false;
        }
        for(char ch:code){
            if(!isNum(ch) && !isAlpha(ch) && ch!='_'){
                return false;
            }
        }
        return true;
    }
    bool validCate(string cat){
        return (cat=="electronics" || cat== "grocery"||cat== "pharmacy"|| cat== "restaurant");
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        map<string,int> prefmap;
        prefmap["electronics"] = 0;
        prefmap["grocery"] = 1;
        prefmap["pharmacy"] = 2;
        prefmap["restaurant"] = 3;
        //check validity of codes
        int n = code.size();
        vector<multiset<string>> temp(4);
        for(int i=0;i<n;i++){
            if(isValid(code[i]) && validCate(businessLine[i]) && isActive[i]){
                temp[prefmap[businessLine[i]]].insert(code[i]);
            }
        }
        vector<string> ans;
        for(auto it:temp){
            for(auto word:it){
                ans.push_back(word);
            }
        }
        return ans;
    }
};