英文链接: https://leetcode.com/problems/merge-two-sorted-lists/  
中文链接: https://leetcode-cn.com/problems/merge-two-sorted-lists/


```
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
```

```
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;

        ListNode dummy(INT_MIN);
        ListNode *cur = &dummy;

        while(l1 != NULL && l2 != NULL)
        {
            if(l1->val <= l2->val)
            {
                cur->next = l1;
                l1 = l1->next;
            }
            else
            {
                cur->next = l2;
                l2 = l2->next;
            }

            cur = cur->next;
        }

        cur->next = l1 != NULL ? l1 : l2;

        return dummy.next;
    }
};
```



```
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;

        if(l1->val <= l2->val)
        {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else
        {
            // 也可以写成 mergeTwoLists(l1, l2->next);
            l2->next = mergeTwoLists(l2->next, l1);
            return l2;
        }
    }
};
```
