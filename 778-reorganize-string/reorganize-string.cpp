class Solution {
public:
    string reorganizeString(string s) {
        int sz = s.size();
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        int mx = *max_element(freq.begin(), freq.end());
        if (mx > (sz + 1) / 2) return "";

        priority_queue<pair<int,char>> pq;
        for (int i = 0; i < 26; i++)
            if (freq[i] > 0) pq.push({freq[i], 'a' + i});

        string ans = "";
        while (pq.size() >= 2) {
            auto p1 = pq.top(); pq.pop();
            auto p2 = pq.top(); pq.pop();

            ans += p1.second;
            ans += p2.second;

            p1.first--;
            p2.first--;

            if (p1.first > 0) pq.push(p1);   // <-- the fix, needs your approval
            if (p2.first > 0) pq.push(p2);   // <-- the fix, needs your approval
        }

        if (pq.size() == 1) ans += pq.top().second;

        return ans;
    }
};