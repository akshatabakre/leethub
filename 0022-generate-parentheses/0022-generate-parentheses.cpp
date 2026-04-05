class Solution {
public:
    string str ="";
    int len;
    vector<string> ans;

    void rec(int ind){
        if(ind>=len){
            bool check = true;
            int p=0;
            for(int i=0;i<str.length();i++){
                if(str[i]=='('){
                    p++;
                }else{
                    p--;
                    if(p<0){
                        check = false;
                        break;
                    }
                }
            }
            if(p){
                check = false;
            }

            if(check){
                ans.push_back(str);
            }
            return;
        }

        str+='(';
        rec(ind+1);
        str.pop_back();
        str+=')';
        rec(ind+1);
        str.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        len = 2*n;
        rec(0);
        return ans;
    }
};
