class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
       for(int i=0;i<nums.size();i++){
            nums[i]=nums[i]%k;
       }
       int maxi=1;
       int prev=nums[0];
       int cnt=0;
       for(int i=0;i<nums.size();i++){
            if(nums[i]==prev){
                cnt++;
            }
            else{
                if(prev==0){
                    maxi=max(maxi,cnt);
                    cnt=1;
                    prev=nums[i];
                    continue;
                }
                if((cnt*prev)%k==prev){
                    maxi=max(maxi,cnt);
                }
                while((cnt*prev)%k!=prev && cnt>0){
                    cnt--;
                }
                maxi=max(maxi,cnt);
                cnt=1;
                prev=nums[i];

            }
       }
       if(prev==0){
                    maxi=max(maxi,cnt);
                    cnt=1;
                    
                }
       else if((cnt*prev)%k==prev){
                    maxi=max(maxi,cnt);
                }
        while((cnt*prev)%k!=prev && cnt>0){
            cnt--;
            }
        maxi=max(maxi,cnt);
       return maxi;
        
    }
};