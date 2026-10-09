
class Solution {

    void deleteNodes(ListNode* startPrev, ListNode* next) {

        ListNode* after = next->next;

        // Reconnect without freeing input nodes
        startPrev->next = after;
    }

    ListNode* removeZeroSum(
        ListNode* DUMMY,
        ListNode* head,
        ListNode* doubleTrav,
        ListNode* trav,
        ListNode* prev,
        ListNode* startPrev,
        int sum = 0
    ) {

        if (!doubleTrav)
            return DUMMY->next;

        if (!trav) {
            return removeZeroSum(
                DUMMY, DUMMY->next,
                doubleTrav->next, doubleTrav->next,
                doubleTrav, doubleTrav, 0
            );
        }

        sum += trav->val;

        if (sum == 0) {

            deleteNodes(startPrev, trav);

            return removeZeroSum(
                DUMMY, DUMMY->next,
                DUMMY->next, DUMMY->next,
                nullptr, DUMMY, 0
            );
        }

        return removeZeroSum(
            DUMMY, head, doubleTrav,
            trav->next, trav, startPrev, sum
        );
    }

public:
    ListNode* removeZeroSumSublists(ListNode* head) {

        ListNode* DUMMY = new ListNode(0);
        DUMMY->next = head;

        head = removeZeroSum(
            DUMMY, head, head, head,
            nullptr, DUMMY, 0
        );

        ListNode* result = DUMMY->next;
        delete DUMMY;

        return result;
    }
};
