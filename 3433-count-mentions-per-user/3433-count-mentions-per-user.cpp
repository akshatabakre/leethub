class Solution {
public:
    bool static cmp(vector<string>&a,vector<string>&b){
        if(a[1]==b[1]){
            if(a[0]=="OFFLINE"){
                return true;
            }
            return false;
        }
        return (stoi(a[1])<stoi(b[1]));
    }
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<int> offline(numberOfUsers,-1);
        int n = events.size();
        vector<int> ans(numberOfUsers,0);
        sort(events.begin(),events.end(),cmp);
        for(auto it:events){
            int tim = stoi(it[1]);
            if(it[0]=="MESSAGE"){
                if(it[2]=="ALL"){
                    for(int i=0;i<numberOfUsers;i++){
                        ans[i]++;
                    }
                }else if(it[2]=="HERE"){
                    for(int i=0;i<numberOfUsers;i++){
                        if(offline[i]<=tim){
                            ans[i]++;
                        }
                    }
                }else{
                    string s = it[2];
                    int i = 2;
                    while(i<s.length()){
                        string id = "";
                        while(i<s.length() && s[i]!=' '){
                            id+=s[i];
                            i++;
                        }
                        ans[stoi(id)]++;
                        i+=3;
                    }
                }
            }else{
                offline[stoi(it[2])] = max(offline[stoi(it[2])],stoi(it[1])+60);
            }
        }
        return ans;
    }
};