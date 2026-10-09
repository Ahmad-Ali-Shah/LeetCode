
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {

    ListNode* tail = nullptr;

    // insert at tail
    void InsertAtTail(ListNode*& head, int value) {

        ListNode* temp = new ListNode(value, nullptr);

        if(!head) {
            head = temp;
            tail = head;
        }
        else {
            tail->next = temp;
            tail = temp;
        }
    }

    // sort linked list in ascending order
    void sortLinkedList(ListNode* head) {

        ListNode* temp1 = head;

        while(temp1 != nullptr) {

            ListNode* temp2 = temp1->next;

            while(temp2 != nullptr) {

                if(temp1->val > temp2->val) {
                    swap(temp1->val, temp2->val);
                }

                temp2 = temp2->next;
            }

            temp1 = temp1->next;
        }
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        ListNode* head = nullptr;
        tail = nullptr;

        // sort each linked list
        for(int i = 0; i < lists.size(); i++) {
            sortLinkedList(lists[i]);
        }

        // flatten all lists into one linked list
        for(int i = 0; i < lists.size(); i++) {

            ListNode* temp = lists[i];

            while(temp != nullptr) {
                InsertAtTail(head, temp->val);
                temp = temp->next;
            }
        }

        // sort the complete linked list
        sortLinkedList(head);

        return head;
    }
};
