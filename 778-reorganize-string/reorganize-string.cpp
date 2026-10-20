class Solution {
public:
    string reorganizeString(string s) {
        int sz = s.size();
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        int mx = *max_element(freq.begin(), freq.end());
        if (mx > (sz + 1) / 2) return "";

        vector<pair<int,char>> v;
        for (int i = 0; i < 26; i++)
            if (freq[i] > 0) v.push_back({freq[i], 'a' + i});
        sort(v.rbegin(), v.rend());

        string ans(sz, ' ');
        int pos = 0;
        for (auto &p : v) {
            int f = p.first;
            char c = p.second;
            while (f--) {
                if (pos >= sz) pos = 1;   
                ans[pos] = c;
                pos += 2;
            }
        }
        return ans;
    }
};