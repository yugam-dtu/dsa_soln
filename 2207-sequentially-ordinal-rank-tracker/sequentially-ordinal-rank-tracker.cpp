class SORTracker {
    priority_queue<pair<int,string>> taken;  // max-heap: worst of the good ones on top
    priority_queue<pair<int,string>, vector<pair<int,string>>, greater<>> rest; // min-heap: best remaining on top
public:
    void add(string name, int score) {
        taken.push({-score, name});
        rest.push(taken.top());
        taken.pop();
    }
    string get() {
        auto best = rest.top();
        rest.pop();
        taken.push(best);
        return best.second;
    }
};