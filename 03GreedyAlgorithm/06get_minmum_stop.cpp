#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

bool cmp(const pair<int,int> &a,const pair<int,int> &b)
{
    return a.first > b.first;
}
//LΪ��㵽�յ���� PΪ����ʼ�������� pair����վ���յ�ľ��룬����վ������
int get_minimum_stop(int L,int P,vector<pair<int,int>> &stop)
{
    std::priority_queue<int> Q;//�洢����������
    int result = 0;//��¼�ӹ������͵ı���
    stop.push_back(make_pair(0,0));//���յ���Ϊһ��ͣ���㣬�����stop���飻
    sort(stop.begin(),stop.end(),cmp);//��ͣ�������յ���� �Ӵ�С ��������
    for(int i = 0;i < stop.size();i++)//��������ͣ����
    {
        int dis = L - stop[i].first;//��ǰҪ�ߵľ��뼴Ϊ��ǰ���յ����L��ȥ��һ��ͣ�������յ����
        while(P < dis && !Q.empty())
        {
            P += Q.top();
            Q.pop();
            result++;
        }
        if(P < dis && Q.empty())
        {
            return -1;
        }
        P = P - dis;
        L = stop[i].first;//����LΪ��ǰͣ�������յ����
        Q.push(stop[i].second);//����ǰͣ��������������������
    }
    return result;
}

int main()
{
    vector<pair<int,int>> stop = {{4,4},{5,2},{11,5},{15,10},{25,10}};
    cout << get_minimum_stop(25,4,stop);
}
