class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        int ans=days;
        for(int i=0;i<meetings.size();i++){
            if(i==0){
                ans-=(meetings[i][1]-meetings[i][0]+1);
            }
            else{
                if(meetings[i][0]<=meetings[i-1][1]){
                    if(meetings[i][1]>meetings[i-1][1]){
                        ans-=meetings[i][1]-meetings[i-1][1];

                    }
                    else{
                        meetings[i][1]=meetings[i-1][1];
                    }
                }
                else{
                    ans-=(meetings[i][1]-meetings[i][0]+1);
                }
            }
        }
        return ans;
        
    }
};