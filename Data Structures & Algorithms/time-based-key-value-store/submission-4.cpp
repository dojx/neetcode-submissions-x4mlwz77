class TimeMap {
private:
    unordered_map<string, vector<pair<string, int>>> m;

public:
    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        if (!m.contains(key)) return "";
        auto& p = m[key];  // reference, avoid copying the whole vector

        int l = 0, r = p.size() - 1;
        while (l < r) {
            int mid = l + (r - l + 1) / 2;
            if (p[mid].second <= timestamp)
                l = mid;
            else
                r = mid - 1;
        }
        return p[l].second <= timestamp ? p[l].first : "";
    }
};
