class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // min heap of (freq,element)
        // hashtable+mapping+sorting

        unordered_map<int, int> freq;
        for (int x : nums)
            freq[x]++;

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        for (auto& [val, f] : freq) {
            pq.push({f, val});
            if (pq.size() > k)
                pq.pop();
        }

        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};