class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> pos;
        
        ListNode* prev = head;
        ListNode* curr = head->next;
        int index = 1;

        while (curr->next != NULL) {
            ListNode* front = curr->next;

            if ((curr->val > prev->val && curr->val > front->val) ||
                (curr->val < prev->val && curr->val < front->val)) {
                pos.push_back(index);
            }

            prev = curr;
            curr = curr->next;
            index++;
        }

        if (pos.size() < 2)
            return {-1, -1};

        int mini = INT_MAX;

        for (int i = 1; i < pos.size(); i++) {
            mini = min(mini, pos[i] - pos[i-1]);
        }

        int maxi = pos.back() - pos.front();

        return {mini, maxi};
    }
};