class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int> diff(n+1,0);
        for(int i=0;i<shifts.size();i++){
            if(shifts[i][2]==0){
                diff[shifts[i][0]]--;
                diff[shifts[i][1]+1]++;
            }else{
                diff[shifts[i][0]]++;
                diff[shifts[i][1]+1]--;
            }
        }
        for(int i=1;i<n;i++){
            diff[i]+=diff[i-1];
        }
        for(int i=0;i<n;i++){
            int upd = diff[i] + s[i] - 'a';
            // if(upd==0){
            //     continue;
            // }else if(upd<0){
            //     s[i] = char('z'+upd+1);
            // }else if(upd>25){
            //     s[i] = char('a'+upd-26);
            // }else{
            //     s[i] = char('a'+upd);
            // }
            if(upd<0){
                while(upd<0){
                    upd+=26;
                }
            }
            s[i] = char('a'+(upd)%26);
        }
        return s;
    }
};