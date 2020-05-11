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
    ListNode* getIntersectionNode(ListNode *headA,ListNode* headB)
    {
        std::set<ListNode*> node_set;//设置查找集合node_set
        while(headA)
        {
            node_set.insert(headA);
            headA = headA -> next;
        }
        while(headB)
        {
            if(node_set.find(headB) != node_set.end())
            {
                return headB;
            }
            headB = headB -> next;
        }
        return NULL;
    }
};

int get_list_length(ListNode *head)
{
    int len = 0;
    while(head)
    {
        len++;
        head = head->next;
    }
    return len;
}

ListNode* forward_long_list(int a,int b,ListNode* head)
{
    while(a > b)
    {
        head = head->next;
        b++;
    }
    return head;
}
class Solution02
{
public:
    ListNode* getIntersection(ListNode *headA,ListNode *headB)
    {
        int lenA = get_list_length(headA);
        int lenB = get_list_length(headB);
        if(lenA > lenB)
        {
            headA = forward_long_list(lenA,lenB,headA);
        }
        else
        {
            headB = forward_long_list(lenB,lenA,headB);
        }
        while(headA && headB)
        {
            if(headA == headB)
            {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
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
    ListNode e;

    a.val = 10;
    b.val = 20;
    c.val = 30;
    d.val = 40;
    e.val = 50;

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = NULL;

    ListNode* headA = &a;

    ListNode f;
    ListNode g;
    ListNode h;
    ListNode y;

    f.val = 10;
    g.val = 20;
    h.val = 30;
    y.val = 60;

    f.next = &g;
    g.next = &h;
    h.next = &d;
    d.next = &y;
    y.next = NULL;

    ListNode* headB = &f;
    Solution01 s01;
    ListNode* head = s01.getIntersectionNode(headA,headB);
    if(head)
    {
        cout << head->val << "\t";
    }
    cout << endl;

    Solution02 s02;
    head = s02.getIntersection(headA,headB);
    if(head)
    {
        cout << head->val << "\t";
    }
}
