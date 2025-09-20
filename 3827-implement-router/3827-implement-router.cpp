class Router {
public:
    queue<array<int,3>> FIFO;
    unordered_set<long long> in_router;
    unordered_map<int, vector<int>> pktToDest;
    unordered_map<int, int> startIdx;
    int limit;

    Router(int memoryLimit) {
        limit = memoryLimit;
    }

    long long encode(int s, int d, int t) {
        return ((long long)s << 40) | ((long long)d << 20) | t;
    }

    bool addPacket(int source, int destination, int timestamp) {
        long long key = encode(source, destination, timestamp);
        if(in_router.count(key)) return false;

        if(FIFO.size() == limit) {
            auto pkt = FIFO.front(); FIFO.pop();
            long long oldKey = encode(pkt[0], pkt[1], pkt[2]);
            in_router.erase(oldKey);
            startIdx[pkt[1]]++;  // logically remove from front
        }

        FIFO.push({source, destination, timestamp});
        in_router.insert(key);
        pktToDest[destination].push_back(timestamp);
        return true;
    }

    vector<int> forwardPacket() {
        if(FIFO.empty()) return {};
        auto pkt = FIFO.front(); FIFO.pop();
        long long key = encode(pkt[0], pkt[1], pkt[2]);
        in_router.erase(key);
        startIdx[pkt[1]]++;  // logically remove from front
        return {pkt[0], pkt[1], pkt[2]};
    }

    int getCount(int destination, int startTime, int endTime) {
        auto &vec = pktToDest[destination];
        int start = startIdx[destination];
        if(start >= (int)vec.size()) return 0;

        auto it1 = upper_bound(vec.begin() + start, vec.end(), endTime);
        auto it2 = lower_bound(vec.begin() + start, vec.end(), startTime);
        return it1 - it2;
    }
};
