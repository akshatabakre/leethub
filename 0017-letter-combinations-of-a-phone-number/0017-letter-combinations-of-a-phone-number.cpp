class Solution {
public:

    string str = "";
    vector<string> ans;
    string digits;
    vector<string> choices;

    void rec(int ind){
        if(ind==digits.size()){
            ans.push_back(str);
            return;
        }

        for(char ch:choices[digits[ind]-'0']){
            str+=ch;
            rec(ind+1);
            str.pop_back();
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        this->digits = digits;
        choices = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        rec(0);
        return ans;
    }
};