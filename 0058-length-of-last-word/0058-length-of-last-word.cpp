class Solution {
public:
    int lengthOfLastWord(string s) {
        //start from last index of string
        //ignore spaces at first
        //then start counting characters(letters)
        //count till ' '
        int i = s.length()-1;
        int ans = 0;
        //skip all spaces from back
        while(s[i]==' '){
            i--;
            if(i<0){
                break;
            }
        }
        //count till next space
        while(s[i]!=' '){
            ans++;
            i--;
            if(i<0){
                break;
            }
        }
        return ans;
    }
};