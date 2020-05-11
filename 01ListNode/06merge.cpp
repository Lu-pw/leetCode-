#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x): val(x),next(NULL) {};
};

class Solution01
{
public:
    ListNode* mergeTwoLists(ListNode* headA, ListNode* headB)
    {
        ListNode head(0);
        ListNode* pre = &head;
        while(headA && headB)
        {
            if(headA->val < headB->val)
            {
                pre->next = headA;
                headA = headA->next;
            }
            else
            {
                pre->next = headB;
                headB = headB->next;
            }
            pre = pre->next;
        }
        if(headA)
        {
            pre->next = headA;
        }
        if(headB)
        {
            pre->next = headB;
        }
        return head.next;
    };
};

bool cmp(const ListNode* a, const ListNode* b)
 {
     return a->val < b->val;
 }
class Solution02 {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode* > node_vec;
        for(int i = 0; i < lists.size(); i++)
        {
            ListNode* head = lists[i];
            while(head)
            {
                node_vec.push_back(head);
                head = head->next;
            }
        }
        if(node_vec.size() == 0)
        {
            return NULL;
        }
        std::sort(node_vec.begin(),node_vec.end(),cmp);
        for(int i = 0; i<node_vec.size(); i++)
        {
            node_vec[i]->next = node_vec[i+1];
        }
        node_vec[node_vec.size()-1]->next = NULL;
        return node_vec[0];
    }
};


ListNode* mergeTwoLists(ListNode* headA, ListNode* headB)
    {
        ListNode head(0);
        ListNode* pre = &head;
        while(headA && headB)
        {
            if(headA->val < headB->val)
            {
                pre->next = headA;
                headA = headA->next;
            }
            else
            {
                pre->next = headB;
                headB = headB->next;
            }
            pre = pre->next;
        }
        if(headA)
        {
            pre->next = headA;
        }
        if(headB)
        {
            pre->next = headB;
        }
        return head.next;
    };
class Solution03
{
    public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        if(lists.size() == 0)
        {
            return NULL;
        }
        if(lists.size() == 1)
        {
            return lists[0];
        }
        if(lists.size() == 2)
        {
            return mergeTwoLists(lists[0],lists[1]);
        }
        int mid = lists.size() / 2;
        std ::vector<ListNode*> sub1_lists;
        std::vector<ListNode*> sub2_lists;
        for(int i = 0;i < mid;i++)
        {
            sub1_lists.push_back(lists[i]);
        };
        for(int i = mid;i < lists.size();i++)
        {
            sub2_lists.push_back(lists[i]);
        }
        ListNode* l1 = mergeKLists(sub1_lists);
        ListNode* l2 = mergeKLists(sub2_lists);
        return mergeTwoLists(l1,l2);
    }
};

int main()
{
    ListNode a(1);
    ListNode b(4);
    ListNode c(6);
    a.next = &b;
    b.next = &c;
    c.next = NULL;

    ListNode f(0);
    ListNode g(5);
    ListNode h(7);

    f.next = &g;
    g.next =&h;
    h.next = NULL;

    Solution01 s01;
    ListNode* head = s01.mergeTwoLists(&a, &f);
    while (head)
    {
        cout << head->val << "\t";
        head = head->next;
    }
    cout <<endl;


    ListNode ak(3);
    ListNode bk(2);
    ListNode ck(5);
    ListNode dk(0);

    vector<ListNode*> node_vec;
    node_vec.push_back(&ak);
    node_vec.push_back(&bk);
    node_vec.push_back(&ck);
    node_vec.push_back(&dk);

    sort(node_vec.begin(),node_vec.end(),cmp);
    for(int i = 0; i < node_vec.size(); i++)
    {
        cout << node_vec[i]->val <<"\t" ;
    }
    cout << endl;

    node_vec.push_back(&a);
    Solution02 s02;
    head = s02.mergeKLists(node_vec);
    while(head)
    {
        cout << head->val << "\t";
        head = head->next;
    }
    cout <<endl;

//    node_vec.push_back(&f);
//    Solution03 s03;
//    head = s03.mergeKLists(node_vec);
//    while(head)
//    {
//        cout << head->val << "\t";
//        head = head->next;
//    }
}
