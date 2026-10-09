
class Solution {

    // insert at head
    void insertAtHead(ListNode*& head, int value) {

        ListNode* temp = new ListNode(value, nullptr);

        temp->next = head;
        head = temp;
    }

    // delete at tail
    int DeleteAttail(ListNode* head) {

        ListNode* temp = head;

        // handle single node
        if(temp->next == nullptr) {

            int data = temp->val;

            delete temp;

            head = nullptr;

            return data;
        }

        while(temp->next->next) {

            temp = temp->next;
        }

        int data = temp->next->val;

        delete temp->next;
        temp->next = nullptr;

        return data;
    }

public:
    ListNode* rotateRight(ListNode* head, int k) {

        if(!head || !head->next || k == 0) {// empty 
            return head;
        }

        int n = 0; // counting no of rotations 

        ListNode* temp = head;

        while(temp) {
            n++;
            temp = temp->next;
        }

        k = k % n;// it can be 10 or 20 or 30 or so on 

        for(int i = 0; i < k; i++) {
            int r = DeleteAttail(head);
            insertAtHead(head, r);
        }

        return head;
    }
};
