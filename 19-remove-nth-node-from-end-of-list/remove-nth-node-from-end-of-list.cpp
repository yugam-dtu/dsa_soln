class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count=1;ListNode* node=head;
        while(node->next!=NULL){
            node=node->next;
            count++;
        }
        if(count==n){return head->next;}     

        node=head;                            
        int count2=1;                     
        while(node->next!=NULL){
            if(count2==count-n){           
                node->next=node->next->next;
                break;
            }
            node=node->next;                count2++;
        }

        return head;
        //helloooooooo
    }
};