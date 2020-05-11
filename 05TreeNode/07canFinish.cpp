#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct GraphNode
{
    int label;
    vector<GraphNode *> neighbors;
    GraphNode(int x):label(x){}
};

//�����Ƿ��л�
class solution
{
public:
    //pair���γ�1���γ�2���γ�1�����γ�2��
    bool canFinish(int numCourses,vector<pair<int,int>> &prerequisites)
    {
        vector<GraphNode *> graph;//�ڽӱ�
        vector<int> visit;//-1δ����0�����ʣ�1�ѷ���
        for(int i =0;i < numCourses;i++)
        {
            graph.push_back(new GraphNode(i));//����ͼ�Ľڵ㣬��������״̬Ϊ��
            visit.push_back(-1);
        }
        for(int i = 0;i < prerequisites.size();i++)
        {
            GraphNode *begin = graph[prerequisites[i].second];
            GraphNode *end = graph[prerequisites[i].first];
            begin->neighbors.push_back(end);//�γ�2ָ��γ�1
        }

        for(int i =0;i < graph.size();i++)
        {
            if(visit[i] == -1 && !DFS_graph(graph[i],visit))
            {
                return false;//����ڵ�û���ʹ�������DFS�����DFS������
            }
        }
        for(int i = 0;i < numCourses;i++)
        {
            delete graph[i];
        }
        return true;
    }

    bool DFS_graph(GraphNode *node,vector<int> &visit)
    {
        visit[node->label] = 0;
        for(int i = 0; i <node->neighbors.size();i++)
        {
            if(visit[node->neighbors[i]->label] == -1)
            {
                if(DFS_graph(node->neighbors[i],visit) == 0)
                {
                    return false;
                }
            }
            else if(visit[node->neighbors[i]->label] == 0)
            {
                return false;
            }
        }
        visit[node->label] = -1;
        return true;
    }
};


class solution02
{
public:
    bool canFinish(int numCourses,vector<pair<int,int>> &prerequisires)
    {
        vector<GraphNode *> graph;
        vector<int> visit;
        for(int i = 0;i < numCourses;i++)
        {
            graph.push_back(new GraphNode(i));
            visit.push_back(0);
        }
        for(int i = 0;i < prerequisires.size();i++)
        {
            GraphNode *begin = graph[prerequisires[i].second];
            GraphNode *end = graph[prerequisires[i].first];
            begin->neighbors.push_back(end);//���++
            visit[prerequisires[i].first]++;
        }
        queue<GraphNode *>Q;
        for(int i = 0;i < numCourses;i++)
        {
            if(visit[i] == 0)
            {
                Q.push(graph[i]);
            }
        }
        while(!Q.empty())
        {
            GraphNode *node = Q.front();
            Q.pop();
            for(int i = 0;i < node->neighbors.size();i++)
            {
                visit[node->neighbors[i]->label]--;
                if(visit[node->neighbors[i]->label] == 0)
                {
                    Q.push(node->neighbors[i]);
                }
            }
        }
        for(int i = 0;i < graph.size();i++)
        {
            delete graph[i];
        }
        for(int i = 0; i < visit.size();i++)
        {
            if(visit[i])
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    vector<pair<int,int>> prerequisites1 = {{0,1},{2,0},{2,1},{3,1}};
    solution s01;
    cout << s01.canFinish(prerequisites1.size(),prerequisites1)<< endl;
    vector<pair<int,int>> prerequisites2 = {{0,1},{2,0},{1,2},{3,1}};
    cout << s01.canFinish(prerequisites2.size(),prerequisites2) << endl;

    solution02 s02;
    cout << s02.canFinish(prerequisites1.size(),prerequisites1)<< endl;
    cout << s02.canFinish(prerequisites2.size(),prerequisites2) << endl;
}
