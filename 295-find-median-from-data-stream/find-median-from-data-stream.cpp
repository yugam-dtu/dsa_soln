class MedianFinder {
public:
    priority_queue<int> max_left_heap;
    priority_queue<int, vector<int>, greater<int>> min_right_heap;

    MedianFinder() {}

    void addNum(int num) {
        if (max_left_heap.empty() || num < max_left_heap.top())
            max_left_heap.push(num);
        else
            min_right_heap.push(num);

        // left may have at most 1 more element than right
        if (max_left_heap.size() > min_right_heap.size() + 1) {
            min_right_heap.push(max_left_heap.top());
            max_left_heap.pop();
        }
        // right must never be bigger than left
        else if (min_right_heap.size() > max_left_heap.size()) {
            max_left_heap.push(min_right_heap.top());
            min_right_heap.pop();
        }
    }

    double findMedian() {
        if (max_left_heap.size() == min_right_heap.size())
            return ((double)max_left_heap.top() + min_right_heap.top()) / 2;
        return max_left_heap.top();
    }
};