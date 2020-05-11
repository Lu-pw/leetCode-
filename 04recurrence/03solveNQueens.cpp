#include <iostream>
#include <vector>

using namespace std;

void generate(int k,//k代表完成了几个皇后的放置（正在放置第k行皇后）
              int n,vector<string> &location,//某次结果存储在location中
              vector<vector<string>> &result,//最终存储至result
              vector<vector<int>> &mark);//表示棋盘的标记数组;

class solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> result;
        vector<vector<int>> mark;
        vector<string> location;
        for(int i = 0;i < n;i++)
        {
            mark.push_back(vector<int>());
            for(int j = 0;j < n;j++)
            {
                mark[i].push_back(0);
            }
            location.push_back("");
            location[i].append(n,'.');
        }
        generate(0,n,location,result,mark);
        return result;
    }
};

void put_down_the_queen(int x,int y,vector<vector<int>> &mark)
{
    static const int dx[] = {-1,1,0,0,-1,-1,1,1};//方向数组
    static const int dy[] = {0,0,-1,1,-1,1,-1,1};
    mark[x][y] = 1;//(x,y)放皇后 标记
    for(int i = 1;i < mark.size();i++)
    {
        for(int j = 0;j < 8;j++)
        {
            int new_x = x + i * dx[j];
            int new_y = y + i * dy[j];
            if(new_x >= 0&&new_y>= 0&&new_x < mark.size()&&new_y < mark.size())
            {
                //检查新位置是否在棋盘内
                mark[new_x][new_y] = 1;
            }
        }
    }
}

void generate(int k,//k代表完成了几个皇后的放置（正在放置第k行皇后）
              int n,vector<string> &location,//某次结果存储在location中
              vector<vector<string>> &result,//最终存储至result
              vector<vector<int>> &mark)//表示棋盘的标记数组
{
    if(k == n)//当k==n时，表示完成了第0至n-1行
    {
        result.push_back(location);//当所有皇后完成放置后，将记录皇后位置的
//        location放入result
        return;
    }
    for(int i = 0;i < n;i++)//按顺序尝试0至n-1列
    {
        if(mark[k][i] == 0)
        {
            vector<vector<int>> tmp_mark = mark;
            location[k][i] = 'Q';
            put_down_the_queen(k,i,mark);
            generate(k+1,n,location,result,mark);
            mark = tmp_mark;
            location[k][i] = '.';
        }
    }
}

int main()
{
    vector<vector<string>> result;
    solution s01;
    result = s01.solveNQueens(4);
    for(int i = 0;i < result.size();i++)
    {
        cout << "i = " << i <<endl;
        for(int j = 0;j < result[i].size();j++)
        {
            cout << result[i][j] << endl;
        }
        cout << endl;
    }
}
