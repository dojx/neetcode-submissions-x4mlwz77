class KthLargest {
    int k;
    priority_queue<int> q;
public:
    KthLargest(int k, vector<int>& nums) : k(k) {
        q = priority_queue<int>(nums.begin(), nums.end());
    }
    
    int add(int val) {
        q.push(val);
        priority_queue<int> tmp = q;
        int i = 1;
        while (i < k) {
            tmp.pop();
            i++;
        }
        return tmp.top();
    }
};
