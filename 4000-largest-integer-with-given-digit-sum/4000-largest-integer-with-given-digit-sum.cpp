class Solution {
public:
    int largestInteger(int n, int s) {
        string str = "";
        while(str.length()<n||s>0){
            int d = min(s,9);
            s -= d;
            str += char('0'+d);
            if(str.length()==n) break;
        }
        if(s>0){
            return -1;
        }else if(s==0 && str==""){
            return 0;
        }
        return stoi(str);
    }
};