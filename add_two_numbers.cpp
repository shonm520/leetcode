#include <stdio.h>


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* addTwoNumbers1(ListNode* l1, ListNode* l2) {     //不能对付大数据
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        int n1 = 0;
        int n2 = 0;
        int pos = 1;
        while(p1 || p2)  {
            if (p1)  {
                n1 += p1->val * pos;
                p1 = p1->next;
            } 
            if (p2)  {
                n2 += p2->val * pos;
                p2 = p2->next;
            }
            pos *= 10;
        }
        int sum = n1 + n2;
        pos = 10;
        ListNode* pHead = NULL;
        ListNode* pCur = NULL;
        while(true)  {
            int val = sum % pos * 10 / pos;   //817 % 100 = 17   17 * 10 / 100 = 1
            ListNode* pNew = new ListNode(val);
            if (pHead == NULL)  {
                pHead = pNew;
                pHead->next = pCur;
                pCur = pNew;
            }
            else  {
                pCur->next = pNew;
                pCur = pNew;
            }
            if (sum % pos == sum) {
                break;
            }
            pos *= 10;
        }
        return pHead;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)  {
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* pHead = NULL;
        ListNode* pCur = NULL;
        int flag = 0;
        while(p1 || p2)  {
            int val = (p1 ? p1->val : 0) + (p2 ? p2->val : 0) + flag;
            flag = val / 10;
            ListNode* pNew = new ListNode(val % 10);
            if (pHead == NULL)  {
                pHead = pNew;
                pHead->next = pCur;
                pCur = pNew;
            }
            else  {
                pCur->next = pNew;
                pCur = pNew;
            }
            if (p1) p1 = p1->next;
            if (p2) p2 = p2->next;
        }
        if (flag > 0)  {
            ListNode* pNew = new ListNode(flag % 10);
            pCur->next = pNew;
        }
        return pHead;
    }
};

int main(int, char**) 
{
    ListNode node1(1);
    ListNode node2(4);
    ListNode node3(3);
    node1.next = &node2;
    node2.next = &node3;
    
    ListNode nodea(9);
    ListNode nodeb(9);
    ListNode nodec(1);
    nodea.next = &nodeb;
    nodeb.next = &nodec;
    
    Solution sl;
    ListNode* pRet = sl.addTwoNumbers(&node1, &nodea);
    while(pRet)  {
        printf("%d ", pRet->val);
        pRet = pRet->next;
    }
}