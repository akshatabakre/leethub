class NumberContainers {
public:
    map<int,int> indextonum;
    map<int,priority_queue<int,vector<int>,greater<int>>> numtoind;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(indextonum.count(index)){
            int prevnum = indextonum[index];
            if(prevnum==number) return;
        }
        indextonum[index] = number;
        numtoind[number].push(index);
    }
    
    int find(int number) {
        if (numtoind.count(number)) {
            auto& min_heap = numtoind[number];

            while (!min_heap.empty() && indextonum[min_heap.top()] != number) {
                min_heap.pop();
            }

            if (!min_heap.empty()) {
                return min_heap.top();
            }
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */