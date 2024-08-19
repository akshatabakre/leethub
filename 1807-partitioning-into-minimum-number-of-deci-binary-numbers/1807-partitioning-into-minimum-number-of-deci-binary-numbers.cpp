class Solution {
public:
    int minPartitions(string n) {
        int maxnum = 0;
        for(int i=0;i<n.length();i++){
            maxnum = max(n[i]-'0',maxnum);
        }
        return maxnum;
    }
};