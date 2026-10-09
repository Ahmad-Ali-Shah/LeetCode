class Solution {

    ListNode* getPrev(ListNode* head, ListNode* node) {
        while (head && head->next != node)
            head = head->next;

        return head;
    }

    void reverse(ListNode* left, ListNode* rgt, ListNode* head) {

        while (left != rgt && left != rgt->next) {
            swap(left->val, rgt->val);

            left = left->next;
            rgt = getPrev(head, rgt);
        }
    }

public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        int countLeft = 1, countRight = 1;

        ListNode* leftOne = head;
        ListNode* rgtone = head;

        while (countLeft < left && leftOne) {
            leftOne = leftOne->next;
            countLeft++;
        }

        while (countRight < right && rgtone) {
            rgtone = rgtone->next;
            countRight++;
        }

        if (!leftOne || !rgtone)
        
            return head;

        reverse(leftOne, rgtone, head);

        return head;
    }
};