class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> min_heap;
    int limit;
    KthLargest(int k, vector<int>& nums) {
        limit = k;
       for(auto num : nums)
       {
        min_heap.push(num);
       }
        while(min_heap.size() > limit)
        {
            min_heap.pop();
        }
    }
    
    int add(int val) {
        min_heap.push(val);
        while(min_heap.size() > limit)
        {
            min_heap.pop();
        }
        return min_heap.top();
    }
};
