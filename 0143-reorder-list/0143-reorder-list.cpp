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

/*
 • Requirements:
o Find the midpoint of the list using slow and fast pointers.
o Reverse the second half of the list in-place.
o Merge/interleave the two halves using pointer rewiring.
o No node data fields may be overwritten; pointers must be manipulated directly.



now for mergiing you need to break from mid next and then integrate it else it will give error 
*/

class Solution {

    ListNode* reverse(ListNode* head) {

        ListNode* current = head;
        ListNode* prev = nullptr;

        while (current) {

            ListNode* nextOne = current->next;

            current->next = prev; // reverse

            prev = current;
            current = nextOne;
        }

        return prev;

        /*
        create two array like one holding half part first other holdiing next half part
        */

    }

public:
    void reorderList(ListNode* head) {

        if (!head || !head->next) {
            return;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {

            

            slow = slow->next;
            fast = fast->next->next;
        }

        // separate the two halves
        ListNode* second = slow->next;
        slow->next = nullptr;

        slow = reverse(second); // reverse the second half

        fast = head;

        while (slow) {

            // placing both

            ListNode* carry = slow->next;

            slow->next = fast->next;
            fast->next = slow;

            slow = carry;
            fast = fast->next->next;// fast jumps of two 
        }
    }
};