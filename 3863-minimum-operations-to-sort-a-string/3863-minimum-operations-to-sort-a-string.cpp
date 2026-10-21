class Solution {
public:
    int minOperations(string s) {
        int ans1 = 0;
        int n = s.length();
        bool sorted = true, sorted1 = true, sorted2 = true;
        char maxchar = 'a', minchar = 'z';
        for(int i=0;i<n-1;i++){
            if(i-1>=0){
                if(s[i]<s[i-1]){
                    sorted1 = false;
                    sorted = false;
                }
            }
            maxchar = max(s[i],maxchar);
            minchar = min(s[i],minchar);
        }
        if(n-2>=0 && s[n-2]>s[n-1]) sorted=false;

        if(sorted)  return 0;

        if(n==2 && s[0]>s[1])   return -1;
        char maxch = 'a', minch = 'z';
        for(int i=1;i<n;i++){
            if(i-1>=1){
                if(s[i]<s[i-1]) sorted2 = false;
            }
            maxch = max(s[i],maxch);
            minch = min(s[i],minch);
        }
        if(!sorted1)     ans1++;
        if(s[n-1]<maxchar)  ans1++;
        if(s[n-1]<minchar)  ans1++;
        int ans2 = 0;

        if(!sorted2)    ans2++;
        if(s[0]>maxch)   ans2++;
        if(s[0]>minch)  ans2++;
        cout<<ans1<<" "<<ans2<<endl;
        return min(ans1,ans2);
    }
};