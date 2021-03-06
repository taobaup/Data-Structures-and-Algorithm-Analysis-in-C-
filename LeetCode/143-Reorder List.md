
英文链接: https://leetcode.com/problems/reorder-list/  
中文链接: https://leetcode-cn.com/problems/reorder-list/


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
	void reorderList(ListNode *head) 
	{
		if (head == NULL || head->next == NULL || head->next->next == NULL) 
			return;

		ListNode *slow = findSlow(head);

		ListNode *mid = slow->next;
		slow->next = NULL;

		ListNode *newHead = reverseList(mid);
		
		merge(head, newHead);
	}

	ListNode* findSlow(ListNode *head) 
	{
        	if(head == NULL)
            		return head;

        	ListNode *fast = head, *slow = head;
        	while(fast != NULL && fast->next != NULL)
        	{
            		fast = fast->next->next;
            		slow = slow->next;            
        	}

        	return slow;
    	}

	ListNode* reverseList(ListNode* head) 
	{
		if(head == NULL)
			return NULL;

       		ListNode *newHead = NULL;
       		ListNode *prev = NULL, *cur = head;

       		while(cur != NULL)
       		{
			ListNode *next = cur->next;
           		if(next == NULL)
				newHead = cur;

           		cur->next = prev;
           		prev = cur;
           		cur = next;
       		}

       		return newHead;
   	}

	void merge(ListNode *head, ListNode *newHead)
	{
		while (head != NULL && newHead != NULL) 
		{
			ListNode *next = head->next;
			head->next = newHead;

			newHead = newHead->next;
			head->next->next = next;

			head = next;
		}
	}
};
```
