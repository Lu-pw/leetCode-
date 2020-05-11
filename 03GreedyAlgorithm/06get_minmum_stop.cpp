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
//L为起点到终点距离 P为起点初始的汽油量 pair加油站至终点的距离，加油站汽油量
int get_minimum_stop(int L,int P,vector<pair<int,int>> &stop)
{
    std::priority_queue<int> Q;//存储油量的最大堆
    int result = 0;//记录加过几次油的变量
    stop.push_back(make_pair(0,0));//将终点作为一个停靠点，添加至stop数组；
    sort(stop.begin(),stop.end(),cmp);//以停靠点至终点距离 从大到小 进行排序
    for(int i = 0;i < stop.size();i++)//遍历各个停靠点
    {
        int dis = L - stop[i].first;//当前要走的距离即为当前距终点距离L减去下一个停靠点至终点距离
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
        L = stop[i].first;//更新L为当前停靠点至终点距离
        Q.push(stop[i].second);//将当前停靠点的汽油量添加至最大堆
    }
    return result;
}

int main()
{
    vector<pair<int,int>> stop = {{4,4},{5,2},{11,5},{15,10},{25,10}};
    cout << get_minimum_stop(25,4,stop);
}
