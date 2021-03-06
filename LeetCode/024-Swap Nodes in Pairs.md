
英文链接: https://leetcode.com/problems/swap-nodes-in-pairs/  
中文链接: https://leetcode-cn.com/problems/swap-nodes-in-pairs/

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
    ListNode* swapPairs(ListNode* head) {
        ListNode *p = head;

        while(p != NULL && p->next != NULL)
        {
            swap(p->val, p->next->val);
            p = p->next->next;
        }

        return head;
    }
};
```

遍历，更改结点位置即可   
虽然提交上面的代码也可以AC，但题意不允许更改结点本身的值   
所以只能采用下面的代码   
注意(cur != NULL)不要写成(cur->next != NULL)   
时间复杂度明显为O(n)，空间复杂度为O(1)

```
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;

        ListNode dummy(-1);
        dummy.next = head;

        ListNode *prev = &dummy;
        ListNode *cur = prev->next;
        ListNode *next = cur->next;

        while(next != NULL)
        {
            cur->next = next->next;
            next->next = cur;
            prev->next = next;

            prev = cur;
            cur = cur->next;
            next = (cur != NULL) ? cur->next : NULL;
        }

        return dummy.next;
    }
};
```
