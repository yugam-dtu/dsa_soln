class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> pq;   // max heap of {dist, index}

        for (int i = 0; i < points.size(); i++) {
            int x = points[i][0], y = points[i][1];
            pq.push({x*x + y*y, i});
            if (pq.size() > k)
                pq.pop();                    // evict the farthest
        }

        vector<vector<int>> ans;
        while (!pq.empty()) {
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }

        return ans;
    }
};