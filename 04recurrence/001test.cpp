#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){};
};

//递归将head指针指向的节点的数据域val，push到vec里
void add_to_vector(ListNode *head,vector<int> &vec)
{
    if(!head)
    {
        return;
    }
    vec.push_back(head->val);
    add_to_vector(head->next,vec);
}

int main()
{
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);
    ListNode e(5);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    vector<int> vec;
    add_to_vector(&a,vec);
    for(int i = 0;i < vec.size();i++)
    {
        printf("%d",vec[i]);
    }
    cout<< endl;
}
