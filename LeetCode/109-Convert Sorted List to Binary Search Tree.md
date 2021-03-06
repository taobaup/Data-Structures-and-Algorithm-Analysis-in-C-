英文链接: https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/  
中文链接: https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/

```
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
```

```
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if (head == NULL) 
        {
            return NULL;
        }

        if (head->next == NULL) 
        {
            return new TreeNode(head->val);
        }

        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = slow;
        while (fast != NULL && fast->next != NULL) 
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        fast = slow->next;
        prev->next = NULL;

        TreeNode *cur = new TreeNode(slow->val);
        if (head != slow) 
        {
            cur->left = sortedListToBST(head);
        }
        cur->right = sortedListToBST(fast);

        return cur;
    }
};
```
