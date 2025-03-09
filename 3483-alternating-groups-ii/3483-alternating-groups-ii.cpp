
class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int counts=0;
        int bs=-1;
        for(int i=0;i<colors.size()-1;i++){
            if(colors[i]==colors[i+1]){
                bs=i+1;
                break;
            }
            else{
                counts++;
            }
        }
        if(bs==-1){
            if(colors[0]==colors.back()){
            return colors.size()+1-k;}
            return colors.size();
        }
        int counte=0;
        int be=-1;
        for(int i=colors.size()-1;i>=0;i--){
            if(colors[i]==colors[i-1]){
                be=i-1;
                break;
            }
            else{
                counte++;
            }
        }
        vector<int> v;
        int count=0;
        for(int i=bs;i<be;i++){
            if(colors[i]!=colors[i+1]){
                count++;
            }
            else{
                v.push_back(count+1);
                count=0;
            }
        }
        if(count>0){
            v.push_back(count+1);
        }
        cout<<counts<<" "<<counte<<endl;
        if(colors.back()!=colors[0]){
            v.push_back(counts+counte+2);
        }
        else{
            v.push_back(counts+1);
            v.push_back(counte+1);

        }
        int ans=0;
        for(int i=0;i<v.size();i++){
            int x=v[i]+1-k;
            if(x>0){
                ans+=x;
            }
        }
        return ans;
        
    }
};