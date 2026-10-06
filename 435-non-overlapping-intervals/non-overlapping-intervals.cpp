class Solution {
bool olap(vector<int>a ,vector<int >b){
    int maxx=max(a[0],b[0]);
    int miny=min(a[1],b[1]);
    if(maxx<miny){
        return true;
    }
    else return false;
}

public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());

    int cnt = 0;
    int prev = 0;                
    for (int i = 1; i < intervals.size(); i++) {
        if (olap(intervals[prev], intervals[i])) {
            cnt++;                     
            if (intervals[i][1] < intervals[prev][1])
                prev = i;              
        } else {
            prev = i;                   
        }
    }
    return cnt;
}
    
};