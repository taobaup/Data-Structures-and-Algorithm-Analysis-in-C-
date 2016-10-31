//Linked List Cycle II
//设慢指针走过的路程为s，则快指针走过的路程为2s
//快慢指针相遇时，慢指针必然没有遍历完链表
//而快指针已经沿环走完了n(n>=1)圈
//设链表长度为L，头结点到环入口点的长度为x
//环入口点到相遇点的长度为a，环的长度为r
//则有2s=s+nr
//s=nr
//x+a=nr=(n-1)r+r
//x+a=(n-1)r+(L-x)
//x=(n-1)r+(L-x-a)
//则当快慢指针相遇时，设置一个新指针
//从头结点出发，其速度与慢指针相等
//则新指针与慢指针相遇点为入环结点
//时间复杂度为O(n)，空间复杂为O(1)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL)
            return NULL;
            
        ListNode *fast=head,*slow=head;
        while(fast&&fast->next)
        {
            fast=fast->next->next;
            slow=slow->next;
            
            if(fast==slow)
            {
                ListNode *slow2=head;
                while(slow2!=slow)
                {
                    slow2=slow2->next;
                    slow=slow->next;
                }
                
                return slow2;
            }
        }
        
        return NULL;
    }
};
