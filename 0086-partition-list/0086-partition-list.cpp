class Solution {

    void insertAtHead(ListNode*& start, int value) {
        ListNode* temp = new ListNode(value);
        temp->next = start;
        start = temp;
    }

    void insertAttail(ListNode*& end, int value) {
        ListNode* temp = new ListNode(value);
        end->next = temp;
        end = temp;
    }

    void insertLeftTox(ListNode*& start, ListNode*& tail, int val) {
        start = new ListNode(val);
        tail = start;
    }

    void insertrightTox(ListNode*& start, ListNode*& end, int val) {
        start = new ListNode(val);
        end = start;
    }

public:
    ListNode* partition(ListNode* head, int x) {

        ListNode* start = nullptr;
        ListNode* leftTail = nullptr;
        ListNode* end = nullptr;
        ListNode* rightHead = nullptr;

        while (head) {

            ListNode* next = head->next;

            if (head->val < x) {
                if (!start)
                    insertLeftTox(start, leftTail, head->val);
                else
                    insertAttail(leftTail, head->val);
            }
            else {
                if (!end)
                    insertrightTox(rightHead, end, head->val);
                else
                    insertAttail(end, head->val);
            }

            head = next;
        }

        if (!start)
            return rightHead;

        leftTail->next = rightHead;
        return start;
    }
};