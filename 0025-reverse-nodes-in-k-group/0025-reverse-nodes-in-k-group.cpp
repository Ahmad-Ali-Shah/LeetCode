class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* start = head;

        int counter = 0;

        while (counter < k && start) {
            counter++;
            start = start->next;
        }

        if (counter < k) {
            return head;
        }

        counter = 0;
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (counter < k) {
          
            ListNode* preserver = curr->next;
            curr->next = prev;

           
            prev = curr;
            curr = preserver;

            counter++;
        }

        
        head->next = reverseKGroup(curr, k);

        return prev;
    }
};