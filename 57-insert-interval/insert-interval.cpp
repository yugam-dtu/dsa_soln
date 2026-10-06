class Solution {
    vector<int> merge(vector<int> a, vector<int> b) {
        int x = min(a[0], b[0]);
        int y = max(a[1], b[1]);
        return {x, y};
    }

    bool olap(vector<int> a, vector<int> b) {
        int maxx = max(a[0], b[0]);
        int miny = min(a[1], b[1]);
        return maxx <= miny;
    }

public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {

        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> res;
        res.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            if (olap(res.back(), intervals[i])) {
                res.back() = merge(res.back(), intervals[i]);
            } else {
                res.push_back(intervals[i]);
            }
        }

        return res;
    }
};