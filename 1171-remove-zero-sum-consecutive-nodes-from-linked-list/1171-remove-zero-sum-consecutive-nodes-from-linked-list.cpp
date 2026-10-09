class Solution {

    ListNode* removeZeroSum(ListNode* head, ListNode* doubleTrav,
                            ListNode* trav, ListNode* startPrev, int sum = 0) {

        if (!doubleTrav)
            return head;

        if (!trav)
            return removeZeroSum(head, doubleTrav->next, doubleTrav->next,
                                 doubleTrav, 0);

        sum += trav->val;

        if (sum == 0) {

            ListNode* after = trav->next;

            if (!startPrev) {
                head = after;
            }
            else {
                startPrev->next = after;
            }

            return removeZeroSum(head, head, head, nullptr, 0);
        }

        return removeZeroSum(head, doubleTrav, trav->next, startPrev, sum);
    }

public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        return removeZeroSum(head, head, head, nullptr, 0);
    }
};