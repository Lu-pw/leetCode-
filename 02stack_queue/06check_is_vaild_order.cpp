#include <iostream>
#include <stack>
#include <queue>

using namespace std;
bool check_is_vaild_order(queue<int> &order)
{
    stack<int> S;//SΪģ��ջ
    int n = order.size();//nΪ���г��ȣ���1--n��ջ
    for(int i = 1;i<= n;i++)
    {
        S.push(i);
        while(!S.empty() && order.front() == S.top())
        {
            S.pop();
            order.pop();
        }
    }
    if(S.empty())
    {
        return true;
    }
    return false;
}

int main()
{
    int n;
    int train;
    scanf("%d",&n);
    while(n)
    {
        scanf("%d",&train);
        while(train)
        {
            queue<int> order;
            order.push(train);
            for(int i = 1;i<n;i++)
            {
                scanf("%d",&train);
                order.push(train);
            }
            if(check_is_vaild_order(order))
            {
                cout << "yes!"<<endl;
            }
            else
            {
                cout << "no!" << endl;
            }
            scanf("%d",&train);
        }
        cout << endl;
        scanf("%d",&n);
    }
}
