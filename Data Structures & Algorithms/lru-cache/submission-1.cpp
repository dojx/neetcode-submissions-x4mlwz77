class LRUCache {
private:
    list<pair<int, int>> l;
    unordered_map<int, list<pair<int, int>>::iterator> m;
    int currSize, maxSize;

public:
    LRUCache(int capacity) {
        currSize = 0;
        maxSize = capacity;
    }
    
    int get(int key) {
        if (!m.contains(key)) return -1;
        auto it = m[key];
        int val = it->second;
        l.push_back({key, val});
        l.erase(it);
        m[key] = prev(l.end());
        return val;
    }
    
    void put(int key, int value) {
        if (m.contains(key)) {
            auto it = m[key];
            l.push_back({key, value});
            l.erase(it);
            m[key] = prev(l.end());
        } else {
            l.push_back({key, value});
            m[key] = prev(l.end());
            if (currSize == maxSize) {
                auto p = l.front();
                m.erase(p.first);
                l.pop_front();
            } else {
                currSize++;
            }
        }
    }
};
