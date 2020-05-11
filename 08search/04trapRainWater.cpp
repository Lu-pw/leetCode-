//https://leetcode-cn.com/problems/trapping-rain-water-ii/
//题号407
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Qitem
{
    int x;
    int y;
    int h;
    Qitem(int _x,int _y,int _h):x(_x),y(_y),h(_h){}
};

struct cmp
{
    bool operator()(const Qitem &a,const Qitem &b)
    {
        return a.h > b.h;
    }
};

class solution
{
public:
    int trapRainWater(vector<vector<int>>& heightMap)
    {
        priority_queue<Qitem,vector<Qitem>,cmp> Q;
        if(heightMap.size() < 3 || heightMap[0].size() < 3)
        {
            return 0;
        }
        int row = heightMap.size();
        int column = heightMap[0].size();
        vector<vector<int>> mark;
        for(int i = 0;i < row;i++)
        {
            mark.push_back(vector<int>());
            for(int j = 0;j < column;j++)
            {
                mark[i].push_back(0);
            }
        }

        for(int i = 0;i < row;i++)
        {
            Q.push(Qitem(i,0,heightMap[i][0]));
            mark[i][0] = 1;
            Q.push(Qitem(i,column - 1,heightMap[i][column - 1]));
            mark[i][column - 1] = 1;
        }
        for(int i = 1;i < column - 1;i++)
        {
            Q.push(Qitem(0,i,heightMap[0][i]));
            mark[0][i] = 1;
            Q.push(Qitem(row - 1,i,heightMap[row - 1][i]));
            mark[row - 1][i] = 1;
        }
        //搜索
        static const int dx[] = {-1,1,0,0};
        static const int dy[] = {0,0,-1,1};
        int result = 0;
        while(!Q.empty())
        {
            int x = Q.top().x;
            int y = Q.top().y;
            int h = Q.top().h;
            Q.pop();
            for(int i = 0; i < 4;i++)
            {
                int newx = x + dx[i];
                int newy = y + dy[i];
                if(newx < 0 || newx >= row ||
                   newy < 0 || newy >= column || mark[newx][newy])
                {
                    continue;
                }
                if(h > heightMap[newx][newy])
                {
                    result += h - heightMap[newx][newy];
                    heightMap[newx][newy] = h;
                }
                Q.push(Qitem(newx,newy,heightMap[newx][newy]));
                mark[newx][newy] = 1;
            }
        }
        return result;
    }
private:


};

int main()
{
    priority_queue<Qitem,vector<Qitem>,cmp> Q;
    Q.push(Qitem(0,0,5));
    Q.push(Qitem(1,3,2));
    Q.push(Qitem(5,2,4));
    Q.push(Qitem(0,1,8));
    Q.push(Qitem(6,7,1));
    while(!Q.empty())
    {
        int x = Q.top().x;
        int y = Q.top().y;
        int h = Q.top().h;
        cout << x <<":" << y <<":" << h <<"  ";
        Q.pop();
    }
    cout << endl;

    vector<vector<int>> heightMap = {{1,4,3,1,3,2},
    {3,2,1,3,2,4},{2,3,3,2,3,1}};
    solution s01;
    cout << s01.trapRainWater(heightMap);
}
