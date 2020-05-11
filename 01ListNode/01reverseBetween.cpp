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
    ListNode* reverseList(ListNode* head)
    {
        ListNode* new_head = NULL;
        while(head)
        {
            ListNode* next = head -> next;
            head -> next = new_head;
            new_head = head;
            head = next;
        }
        return new_head;
    }
};

class Solution02
{
public:
    ListNode* reverseBetween(ListNode* head,int m, int n)
    {
        int changelen = n-m+1;//计算需要逆置的节点数
        ListNode* pre_head = NULL;//初始化开始逆置的节点的前驱
        ListNode* result = head;//最终转换后的链表头节点，非特殊情况即为head
        while(head && --m)
        {
            pre_head = head;
            head = head -> next;
        }
        ListNode* modity_list_tail = head;//将modity_list_tail指向当前的head，即逆置后的链表尾
        ListNode* new_head = NULL;
        while(head && changelen)//逆置changelen个节点
        {
            ListNode* next = head -> next;
            head -> next = new_head;
            new_head = head;
            head = next;
            changelen--;
        }
        modity_list_tail -> next = head;
        if(pre_head)
        {
            pre_head->next = new_head;
        }
        else
        {
            result = new_head;
        }
        return result;
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

    ListNode* head = &a;
    while(head)
    {
        cout << head->val;
        head = head -> next;
    }
    cout << "Hello world!" << endl;

//    Solution01 s01;
//    head = s01.reverseList(&a);
//    while(head)
//    {
//        cout << head->val;
//        head = head -> next;
//    }
//    cout << "Hello world!" << endl;
//和下一行代码不能同时运行


    Solution02 s02;
    head = s02.reverseBetween(&a,2,4);
    while(head)
    {
        cout << head->val;
        head = head -> next;
    }
    cout << "Hello world!" << endl;


    set<int> test_set;//STL set
    const int A_LEN = 7;
    const int B_LEN = 8;

    int aa[A_LEN] = {5,1,4,8,10,1,3};
    int bb[B_LEN] = {2,7,6,3,1,6,0,1};

    for(int i = 0;i < A_LEN;i++)
    {
        test_set.insert(aa[i]);
    }
    for(int i = 0; i < B_LEN; i++)
    {
        if(test_set.find(bb[i]) != test_set.end())
        {
            cout << "b["<<i << "] in array A:" << bb[i] << "\t";
        }
    }
    cout << endl;
    return 0;


}
