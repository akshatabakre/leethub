class Solution {
public:
    string s;
    bool func(int l,int r){
        if(l==r){
            if(s[l]=='t'){
                return 1;
            }else{
                return 0;
            }
        }
        if(s[l]=='!'){
            return !func(l+2,r-1);
        }else if(s[l]=='&'){
            int x = 1;
            for(int i=l+2;i<=r-1;i++){
                if(s[i]==','){
                    continue;
                }
                if(s[i]=='f'){
                    x=0;
                    break;
                }
                if(s[i]=='t'){
                    continue;
                }
                int nr = i+1;
               
                int cnt = 0;

                while(nr <= r){
                    if(s[nr] == '(') cnt++;
                    else if(s[nr] == ')') cnt--;

                    if(cnt == 0) break;
                    nr++;
                }
                x = (x*func(i,nr));
                i = nr;
                
            }
            return x;
        }else if(s[l]=='|'){
            int x = 0;
            for(int i=l+2;i<=r-1;i++){
                if(s[i]==','){
                    continue;
                }
                if(s[i]=='t'){
                    x=1;
                    break;
                }
                if(s[i]=='f'){
                    continue;
                }
                int nr = i+1;
                int cnt = 0;

                while(nr <= r){
                    if(s[nr] == '(') cnt++;
                    else if(s[nr] == ')') cnt--;

                    if(cnt == 0) break;
                    nr++;
                }
                x = (x|func(i,nr));
                i = nr;
                
            }
            return x;
        }
        return 0;
    }
    bool parseBoolExpr(string expression) {
        s = expression;
       
        return func(0,expression.length()-1);
    }
};