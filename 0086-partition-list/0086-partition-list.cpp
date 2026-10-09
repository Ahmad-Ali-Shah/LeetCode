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

public:
    ListNode* partition(ListNode* head, int x) {

        ListNode* start = nullptr;
        ListNode* end = nullptr;

        ListNode* leftTail = nullptr;
        ListNode* rightHead = nullptr;

        while (head) {

            ListNode* next = head->next;
            head->next = nullptr;

            if (head->val < x) {

                if (!start) {
                    start = head;
                    leftTail = head;
                }
                else {
                    leftTail->next = head;
                    leftTail = head;
                }
            }
            else {

                if (!end) {
                    end = head;
                    rightHead = head;
                }
                else {
                    insertAttail(end, head->val);
                }
            }

            head = next;
        }

        if (!start)
            return rightHead;

        leftTail->next = rightHead;

        return start;
    }
};