class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int head, tail, ans = 0;
        head = tail = 0;
        map<char,int> f;
        f[s[tail]]++;
        while(tail<n){
            while(head+1<n && f[s[head+1]]==0){
                head++;
                f[s[head]]++;
            }
            ans = max(ans,head-tail+1);
            if(tail==head){
                f[s[tail]]--;
                tail++;
                f[s[tail]]++;
                head = tail;
            }else{
                f[s[tail]]--;
                tail++;
            }
        }

        return ans;
    }
};