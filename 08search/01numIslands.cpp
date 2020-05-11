#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

class solution
{
public:
    int numIslands(vector<vector<char>>& grid)
    {
        vector<vector<int>> mark;
        for(int i = 0;i < grid.size();i++)
        {
            mark.push_back(vector<int>());
            for(int j = 0;j < grid.size();j++)
            {
                mark[i].push_back(0);
            }
        }
        int island_num = 0;
        for(int i = 0;i < grid.size();i++)
        {
            for(int j = 0;j < grid[i].size();j++)
            {
                if(grid[i][j] == '1' && mark[i][j] == 0)
                {
                    BFS(mark,grid,i,j);
                    island_num++;
                }
            }
        }
        return island_num;
    };
    void DFS(vector<vector<int>> &mark,vector<vector<char>> &grid,int x,int y)
    {
        mark[x][y] = 1;//标记已搜寻位置
        static const int dx[] = {1,-1,0,0};
        static const int dy[] = {0,0,-1,1};
        for(int i = 0;i < 4;i++)
        {
            int newx = x + dx[i];
            int newy = y + dy[i];
            if(newx < 0 || newx >= mark.size() ||
               newy < 0 || newy >= mark[newx].size())
            {
                //超出数组边界
                continue;
            }
            if(grid[newx][newy] == '1' && mark[newx][newy] == 0)
            {
                DFS(mark,grid,newx,newy);
            }
        }
        return;
    };

    void BFS(vector<vector<int>> &mark,vector<vector<char>> &grid,int x,int y)
    {
        static int dx[] = {-1,1,0,0};
        static int dy[] = {0,0,-1,1};
        mark[x][y] = 1;
        queue<pair<int,int>> Q;
        Q.push(make_pair(x,y));
        mark[x][y] = 1;
        while(!Q.empty())
        {
            x = Q.front().first;
            y = Q.front().second;
            Q.pop();
            for(int i = 0;i < 4;i++)
            {
                int newx = dx[i] + x;
                int newy = dy[i] + y;
                if(newx < 0 || newx >= mark.size()
                   || newy < 0 || newy >= mark[newx].size())
                {
                    continue;
                }
                if(mark[newx][newy] == 0 && grid[newx][newy] == '1')
                {
                    Q.push(make_pair(newx,newy));
                    mark[newx][newy] = 1;
                }
            }
        }
        return;
    }
};

int main()
{
    vector<vector<char>> grid = {{'1','1','1','0','0'},
    {'1','1','0','0','0'},{'1','0','0','0','0'},
    {'0','0','1','0','0'},{'0','0','0','1','1'}};
    solution s01;
    cout << s01.numIslands(grid);
}
