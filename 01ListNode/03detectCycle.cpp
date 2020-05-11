#include <iostream>
#include <set>
#include <algorithm>
#include <array>
using namespace std;



struct ListNode
{
    int val;
    ListNode *next;

};

class Solution01
{
public:
    ListNode* detectCycle(ListNode* head)
    {
        std::set<ListNode*> node_set;
        while(head)
        {
            if(node_set.find(head) == node_set.end())
            {
                node_set.insert(head);
            }
            else
            {
                return head;
            }
            head = head->next;
        }
        return NULL;
    }
};

class Solution02
{
public:
    ListNode* findCycle(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* meet = NULL;
        while(fast)
        {
            slow = slow->next;
            fast = fast->next;
            if(!fast)
            {
                return NULL;
            }
            fast = fast->next;
            if(fast == slow)
            {
                meet = fast;
                break;
            }
        }
        while(head && meet)
        {
            if(head == meet)
            {
                return head;
            }
            head = head->next;
            meet = meet->next;
        }
        return NULL;
    }
};
int main()
{
    ListNode a;
    ListNode b;
    ListNode c;
    ListNode d;

    a.val = 10;
    b.val = 20;
    c.val = 30;
    d.val = 40;

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &b;

    Solution01 s01;
    ListNode* head = s01.detectCycle(&a);
    if(head)
    {
        cout << head->val;
    }
    cout << endl;

    Solution02 s02;
    head = s02.findCycle(&a);
    if(head)
    {
        cout << head->val;
    }
    cout << endl;
}
