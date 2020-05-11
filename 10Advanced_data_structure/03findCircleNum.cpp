//https://leetcode-cn.com/problems/friend-circles/
//题号547
#include <iostream>
#include <vector>

using namespace std;

class solution
{
public:
    int findCircleNum(vector<vector<int>>& M)
    {
        vector<int> visit(M.size(),0);
        int count = 0;
        for(int i = 0;i < M.size();i++)
        {
            if(visit[i] == 0)
            {
                DFS_graph(i,M,visit);
                count++;
            }
        }
        return count;
    };
private:
    void DFS_graph(int u,vector<vector<int>>& graph,vector<int>& visit)
    {
        visit[u] = 1;
        for(int i = 0;i < graph[u].size();i++)
        {
            if(visit[i] == 0 && graph[u][i] == 1)
            {
                DFS_graph(i,graph,visit);
            }
        }
    }
};

//并查集:集合实现
class DisjoinSet
{
public:
    DisjoinSet(int n)//设置表示集合数组id[i],
    {//初始时每个元素构成一个单元素集合，编号为i的元素属于集合i
        for(int i = 0;i < n;i++)
        {
            _id.push_back(i);
        }
    }
    int find(int p)//查询元素p属于哪个集合时直接返回id[i]
    {
        return _id[p];
    }
    void union_(int p,int q)
    {//合并时，若两个元素属于同一个集合，则直接返回
        int pid = find(p);
        int qid = find(q);
        if(pid == qid)
        {
            return;
        }
        for(int i = 0;i < _id.size();i++)
        {
            if(_id[i] == pid)
            {
                _id[i] = qid;
            }
        }
    }
    void print_set()
    {
        cout << "元素：";
        for(int i = 0;i < _id.size();i++)
        {
            cout << _id[i] << " ";
        }
        cout << endl;
    }
private:
    vector<int> _id;
};

//并查集:tree实现
class Disjoin_Set
{
public:
    Disjoin_Set(int n){
        for(int i = 0;i < n;i++)
        {
            _id.push_back(i);
            _size.push_back(1);
        }
        _count = n;
    }
    int find(int p)
    {
        while(p != _id[p]){
            _id[p] = _id[_id[p]];
            p = _id[p];
        }
        return p;
    }
    void union_(int p,int q){
        int i = find(p);
        int j = find(q);
        if(i == j)
        {
            return;
        }
        if(_size[i] < _size[j]){
            _id[i] = j;
            _size[j] += _size[i];
        }
        else
        {
            _id[j] = i;
            _size[i] += _size[j];
        }
        _count--;
    }
    void print_set()
    {
        cout << "元素：";
        for(int i = 0;i < _id.size();i++)
        {
            cout << i << " ";
        }
        cout << endl;
        cout << "集合：";
        for(int i = 0;i < _id.size();i++)
        {
            cout << _id[i] << " ";
        }
        cout << endl;
    }
    int count(){
        return _count;
    }
private:
    vector<int> _id;
    vector<int> _size;
    int _count;
};

//并查集解决问题
class solution02
{
public:
    int findCircleNum(vector<vector<int>>& M)
    {
        Disjoin_Set disjoin_set(M.size());
        for(int i = 0;i < M.size();i++)
        {
            for(int j = i+1;j < M.size();j++)
            {
                if(M[i][j])
                {
                    disjoin_set.union_(i,j);
                }
            }
        }
        return disjoin_set.count();
    }
};

int main()
{
    vector<vector<int>> M = {{1,1,0},{1,1,0},{0,0,1}};
    solution s01;
    cout << s01.findCircleNum(M) <<endl;
    cout << "\nnext DisjoinSet:"<<endl;
    DisjoinSet disjoint_set(8);
    disjoint_set.print_set();
    cout << "union(0,5): ";
    disjoint_set.union_(0,5);
    disjoint_set.print_set();
    cout << disjoint_set.find(0) <<": "<< disjoint_set.find(5)<<endl;
    cout << disjoint_set.find(2) << ":" << disjoint_set.find(5) << endl;
    disjoint_set.union_(2,4);
    disjoint_set.print_set();
    disjoint_set.union_(0,4);
    disjoint_set.print_set();
    cout << disjoint_set.find(2) << ":" << disjoint_set.find(5) << endl;

    cout << "\nnext DisjoinSet:"<<endl;
    Disjoin_Set disjoint_set2(8);
    disjoint_set2.print_set();
    cout << "union(0,5): \n";
    disjoint_set2.union_(0,5);
    disjoint_set2.print_set();
    cout << disjoint_set2.find(0) <<": "<< disjoint_set2.find(5)<<endl;
    cout << disjoint_set2.find(2) << ":" << disjoint_set2.find(5) << endl;
    cout << "union(2,4): \n";
    disjoint_set2.union_(2,4);
    disjoint_set2.print_set();
    cout << "union(0,4): \n";
    disjoint_set2.union_(0,4);
    disjoint_set2.print_set();
    cout << disjoint_set2.find(2) << ":" << disjoint_set2.find(5) << endl;

    cout << "\nnext answer: \n";
    solution02 s02;
    cout << s02.findCircleNum(M);
}
