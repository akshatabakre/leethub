class Solution {
public:
    int minimumPushes(string word) {
        //count distinct letters, if the count of distinct letters is lesser than or equal to 8, return length of word
        unordered_map<char,int> mp;
        for(char c:word){
            mp[c]++;
        }
        vector<int> freq;
        for(auto i:mp){
            freq.push_back(i.second);
        }
        sort(freq.begin(),freq.end());
        if(freq.size()<=8){
            return word.length();
        } else if(freq.size()<=16){
            int pushes = 0;
            int twice = freq.size() - 8;
            for(int i=0;i<twice;i++){
                pushes += (2*freq[i]);
            }
            for(int i=twice;i<freq.size();i++){
                pushes += (freq[i]);
            }
            return pushes;
        } else if(freq.size()<=24){
            int pushes = 0;
            int thrice = freq.size() - 16;
            for(int i=0;i<thrice;i++){
                pushes += (3*freq[i]);
            }
            for(int i=thrice;i<thrice+8;i++){
                pushes += (2*freq[i]);
            }
            for(int i=thrice+8;i<freq.size();i++){
                pushes += (freq[i]);
            }
            return pushes;
        } else {
            int pushes = 0;
            int fours = freq.size() - 24;
            for(int i=0;i<fours;i++){
                pushes += (4*freq[i]);
                cout<<"4\t"<<pushes<<endl;
            }
            for(int i=fours;i<fours+8;i++){
                pushes += (3*freq[i]);
            }
            for(int i=fours+8;i<fours+16;i++){
                pushes += (2*freq[i]);
            }
            for(int i=fours+16;i<freq.size();i++){
                pushes += (freq[i]);
            }
            return pushes;
        }
        return -1;
    }
};