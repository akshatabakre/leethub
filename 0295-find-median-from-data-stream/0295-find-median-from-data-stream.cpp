class MedianFinder {
public:
        multiset<int> ms1, ms2;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(ms1.empty()){
            ms1.insert(num);
        }else{
            if(num<=*ms1.rbegin()){
                ms1.insert(num);
            }else{
                ms2.insert(num);
            }
        }

        if(ms1.size()>ms2.size()+1){
                ms2.insert(*ms1.rbegin());
                ms1.erase(ms1.find(*ms1.rbegin()));

            }else if(ms2.size()>ms1.size()){
                ms1.insert(*ms2.begin());
                ms2.erase(ms2.find(*ms2.begin()));
            }
    }
    
    double findMedian() {
        double median = 0;
        if(ms1.size()==1+ms2.size()){
            median = *ms1.rbegin();
        }else{
            median = *ms1.rbegin() + *ms2.begin();
            median /= 2.0;
        }
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */