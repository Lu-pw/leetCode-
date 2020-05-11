#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

struct RandomListNode
{
    int label;//带有随机指针的链表节点
    RandomListNode *next,*random;
    RandomListNode(int x):label(x),next(NULL),random(NULL){}
};

//返回时深度拷贝后的链表
//深度拷贝：构造生成一个完全新的链表，即使将原链表毁坏，新链表可独立使用
class Solution01
{
public:
    RandomListNode* copyRandomList(RandomListNode *head)
    {
        std::map<RandomListNode* ,int> node_map;//地址到节点位置的map
        std::vector<RandomListNode*> node_vec;//使用vector根据存储节点的位置访问地址
        RandomListNode *ptr = head;
        int i = 0;
        while(ptr)
        {
            //将新链表节点push入node_vec，生成了新链表节点位置到地址的map
            node_vec.push_back(new RandomListNode(ptr->label));
            node_map[ptr] = i;//记录原始链表地址至节点位置的node_map;
            ptr = ptr->next;
            i++;//遍历原始列表，记录节点位置；
        }
        node_vec.push_back(0);
        ptr = head;
        i = 0; //再次遍历原始列表，连接新链表的next指针，random指针；
        while(ptr)
        {
            node_vec[i]->next =node_vec[i+1]; //连接新链表的next指针
            if(ptr->random)//当random指针不为空时
            {
                int id = node_map[ptr->random];//根据node_map确认
                node_vec[i]->random = node_vec[id]; //原链表random指针指向的位置即id；连接新链表的random指针
            }
            ptr = ptr->next;
            i++;
        }
        return node_vec[0];
    }
};

int main()
{
    std::map<RandomListNode* ,int > node_map;
    RandomListNode a(5);
    RandomListNode b(3);//设置一个节点map，key为节点地址，value为整型
    RandomListNode c(6);
    a.next = &b;
    b.next = &c;
    a.random = &c;
    b.random = &a;
    c.random = &c;
    node_map[&a]  = 1;
    node_map[&b] = 2;
    node_map[&c] = 3;
    cout << "a.random id = " << node_map[a.random] << endl;
    cout << "b.random id = " << node_map[b.random] << endl;
    cout << "c.random id = " << node_map[c.random] << endl;

    Solution01 s01;
    RandomListNode* head = s01.copyRandomList(&a);
    while(head)
    {
        cout <<head->label << "\t" << head->next << "\t" << head ->random << endl;
        head = head->next;

    }
}
