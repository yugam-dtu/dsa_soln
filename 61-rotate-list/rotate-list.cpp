class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return head;   // fix 2

        ListNode *node =head;
        int count =1;
        while(node->next!=NULL){
            node=node->next;
            count++;
        }
        node->next=head;

        int m=k%count;
        int alpha=count-m;
        int count2=1;
        ListNode*node2=head;
        while(count2!=alpha){
            node2=node2->next;
            count2++;
        }
        ListNode* newHead = node2->next;  // fix 1
        node2->next=NULL;

        return newHead;                   // fix 1
    }
};