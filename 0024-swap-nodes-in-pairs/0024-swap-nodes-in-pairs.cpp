class Solution {

    void swapNOdes(ListNode* prev, ListNode* start, ListNode* end) {

        prev->next = end;
        start->next = end->next;
        end->next = start;
    }

public:
    ListNode* swapPairs(ListNode* head) {

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;

        while(prev->next && prev->next->next) {

            ListNode* start = prev->next;
            ListNode* end = start->next;

            swapNOdes(prev, start, end);

            // move to the next pair
            prev = start;
        }

        ListNode* result = dummy->next;
        delete dummy;

        return result;
    }
};