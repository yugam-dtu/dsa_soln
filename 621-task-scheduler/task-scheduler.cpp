class Solution {
public:
    int leastInterval(vector<char>& task, int n) {
        int maxF = 0, count = 0;
        int sz = task.size();
        map<int,int> mp;
        for (int i = 0; i < sz; i++) {
            mp[task[i]]++;
            if (mp[task[i]] > maxF) {
                maxF = mp[task[i]];
                count = 1;                 // first letter at this new max
            }
            else if (mp[task[i]] == maxF) {
                count++;                   // another letter reached the max
            }
        }
        return max(sz, (n + 1) * (maxF - 1) + count);
    }
};