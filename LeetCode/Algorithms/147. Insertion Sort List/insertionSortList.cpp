// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(INT_MIN);
        ListNode *cur = &dummy;

        while(head != NULL)
        {
            ListNode *t = head->next;
            cur = &dummy;

            while(cur->next != NULL && cur->next->val <= head->val)
                cur = cur->next;

            head->next = cur->next;
            cur->next = head;
            head = t;
        }

        return dummy.next;
    }
};
