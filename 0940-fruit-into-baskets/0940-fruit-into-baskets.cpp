class Solution {
public:
    bool checkValidity(int ind,vector<int>& fruits,map<int,int>& types){
        return ( (types.count(fruits[ind])==1 && types.size()<=2) || (types.count(fruits[ind])==0 && types.size()<2) );
    }
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int head = 0, tail = 0;
        map<int,int> types;
        types[fruits[0]]++;
        int ans = 0;
        while(tail<n){
            while(head+1<n && checkValidity(head+1,fruits,types)){
                head++;
                types[fruits[head]]++;
            }
            // cout<<tail<<" "<<head<<endl;
            ans = max(head-tail+1,ans);
            types[fruits[tail]]--;
            if(types[fruits[tail]]==0){
                types.erase(fruits[tail]);
            }
            if(head==tail){
                tail++;
                head = tail;
            }else{
                tail++;
            }
        }
        return ans;
    }
};