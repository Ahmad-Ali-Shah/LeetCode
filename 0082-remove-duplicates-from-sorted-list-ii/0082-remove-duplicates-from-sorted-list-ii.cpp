
class Solution {

    void DeleteParticularNode(ListNode* part, ListNode* prev) {
        prev->next = part->next;
        delete part;
    }

public:
    ListNode* deleteDuplicates(ListNode* head) {

        if(!head)
            return head;

        ListNode* prevMost = nullptr;
        ListNode* prev = head;

        while(prev) {

            ListNode* trav = prev->next;
            ListNode* pp = prev;
            bool isFound = false;

            while(trav) {

                if(prev->val == trav->val) {
                    ListNode* temp = trav->next;

                    DeleteParticularNode(trav, pp);

                    isFound = true;
                    trav = temp;
                }
                else {
                    pp = trav;
                    trav = trav->next;
                }
            }

            if(isFound) {

                if(prev == head) {
                    head = prev->next;
                    delete prev;
                    prev = head;
                    prevMost = nullptr;
                }
                else {
                    ListNode* temp = prev->next;
                    DeleteParticularNode(prev, prevMost);
                    prev = temp;
                }

            }
            else {
                prevMost = prev;
                prev = prev->next;
            }
        }

        return head;
    }
};
