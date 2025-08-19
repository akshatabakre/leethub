class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int XY = 0, YX = 0;
        int n = s1.length();
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]){
                if(s1[i]=='x'){
                    XY++;
                }else{
                    YX++;
                }
            }
        }
        if((XY+YX)%2!=0){
            return -1;
        }
        int ans = 0;
        ans += ((XY+1)/2);
        ans += ((YX+1)/2);
        
        return ans;
    }
};