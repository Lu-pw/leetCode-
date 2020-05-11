#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

struct RandomListNode
{
    int label;//�������ָ�������ڵ�
    RandomListNode *next,*random;
    RandomListNode(int x):label(x),next(NULL),random(NULL){}
};

//����ʱ��ȿ����������
//��ȿ�������������һ����ȫ�µ�������ʹ��ԭ����ٻ���������ɶ���ʹ��
class Solution01
{
public:
    RandomListNode* copyRandomList(RandomListNode *head)
    {
        std::map<RandomListNode* ,int> node_map;//��ַ���ڵ�λ�õ�map
        std::vector<RandomListNode*> node_vec;//ʹ��vector���ݴ洢�ڵ��λ�÷��ʵ�ַ
        RandomListNode *ptr = head;
        int i = 0;
        while(ptr)
        {
            //��������ڵ�push��node_vec��������������ڵ�λ�õ���ַ��map
            node_vec.push_back(new RandomListNode(ptr->label));
            node_map[ptr] = i;//��¼ԭʼ�����ַ���ڵ�λ�õ�node_map;
            ptr = ptr->next;
            i++;//����ԭʼ�б���¼�ڵ�λ�ã�
        }
        node_vec.push_back(0);
        ptr = head;
        i = 0; //�ٴα���ԭʼ�б������������nextָ�룬randomָ�룻
        while(ptr)
        {
            node_vec[i]->next =node_vec[i+1]; //�����������nextָ��
            if(ptr->random)//��randomָ�벻Ϊ��ʱ
            {
                int id = node_map[ptr->random];//����node_mapȷ��
                node_vec[i]->random = node_vec[id]; //ԭ����randomָ��ָ���λ�ü�id�������������randomָ��
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
    RandomListNode b(3);//����һ���ڵ�map��keyΪ�ڵ��ַ��valueΪ����
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
