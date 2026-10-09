class Solution {

    void insertAtTail(ListNode*& headA, ListNode*& tail, int value) {

        ListNode* temp = new ListNode(value);

        if (!headA) {
            headA = temp;
            tail = temp;
        }
        else {
            tail->next = temp;
            tail = temp;
        }
    }

public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {

        ListNode* leftPointer = nullptr;
        ListNode* rightPointer = nullptr;
        ListNode* intersection = nullptr;

        ListNode* leftPointerT = nullptr;
        ListNode* rightPointerT = nullptr;
        ListNode* intersectionT = nullptr;

        ListNode* tempA = headA;
        ListNode* tempB = headB;

        while (tempA && tempB && tempA != tempB) {

            insertAtTail(leftPointer, leftPointerT, tempA->val);
            insertAtTail(rightPointer, rightPointerT, tempB->val);

            tempA = tempA->next;
            tempB = tempB->next;
        }

     
        while (tempA && tempB == nullptr)
            tempA = tempA->next;

        while (tempB && tempA == nullptr)
            tempB = tempB->next;

       
        tempA = headA;
        tempB = headB;

        while (tempA != tempB) {
            tempA = (tempA == nullptr) ? headB : tempA->next;
            tempB = (tempB == nullptr) ? headA : tempB->next;
        }

        return tempA;
    }
};