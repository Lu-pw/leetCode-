#include <iostream>


struct ListNode
{
    int val;
    ListNode* next;
};

class Solution01
{
public:
    ListNode* partition1(ListNode* head,int x)
    {
        ListNode little_node;
        ListNode big_node;
        little_node.val = 0;
        big_node.val = 0;
        ListNode* little = &little_node;
        ListNode* big = &big_node;
        while(head)
        {
            if(head->val < x )
            {
                little->next = head;
                little = head;
            }else
            {
                big->next = head;
                big = head;
            }
            head = head->next;
        }
        little->next = big_node.next;
        big->next = NULL;
        return little_node.next;
    }
};
using namespace std;
int main(){
    ListNode a;
    ListNode b;
    ListNode c;
    ListNode d;
    ListNode e;

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = NULL;

    a.val = 10;
    b.val = 40;
    c.val = 30;
    d.val = 20;
    e.val = 50;

    Solution01 s01;
    ListNode* head = s01.partition1(&a,30);
    while(head)
    {
        cout << head->val << "\t";
        head = head->next;
    }
    cout << endl;
}
