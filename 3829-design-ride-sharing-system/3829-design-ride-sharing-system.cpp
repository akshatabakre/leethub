class RideSharingSystem {
public:
    unordered_map<int,bool> ridact;
    queue<int> riders, drivers;
    RideSharingSystem() {
        
    }
    
    void addRider(int riderId) {
        ridact[riderId] = true;
        riders.push(riderId);
    }
    
    void addDriver(int driverId) {
        drivers.push(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        int r = -1, d = -1;
        while(!riders.empty() && ridact[riders.front()]==false){
            riders.pop();
        }
        if(!riders.empty())
            r = riders.front();
        if(!drivers.empty())
            d = drivers.front();
        if(r==-1 || d==-1){
            return {-1,-1};
        }
        riders.pop();   drivers.pop();
        return {d,r};
    }
    
    void cancelRider(int riderId) {
        ridact[riderId] = false;
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */