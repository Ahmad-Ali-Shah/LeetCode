class Solution {

  

    ListNode* removeZeroSum(ListNode* head,
                            ListNode* doubleTrav,
                            ListNode* trav,
                            ListNode* prev,
                            ListNode* startPrev,
                            int sum = 0) {

        if (!doubleTrav) return head;

        if (!trav)
            return removeZeroSum(head, doubleTrav->next, doubleTrav->next, doubleTrav, doubleTrav, 0);

        sum += trav->val;

        if (sum == 0) {

            ListNode* after = trav->next;

            if (!startPrev) {
                head = after;
            } else {
                startPrev->next = after;
            }

            return removeZeroSum(head, head, head, nullptr, nullptr, 0);
        }

        return removeZeroSum(head, doubleTrav, trav->next, trav, startPrev, sum);
    }

public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        return removeZeroSum(head, head, head, nullptr, nullptr, 0);
    }
};