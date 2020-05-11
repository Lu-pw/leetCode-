#include <iostream>
#include <vector>
using namespace std;
//�ڽӾ���
struct GraphNode
{
    int label;
    vector<GraphNode *> neighbors;
    GraphNode(int x):label(x){};
};

int main()
{
    const int MAX_N = 5;
    GraphNode *Graph[MAX_N];

    for(int i =0;i < MAX_N;i++)
    {
        Graph[i] = new GraphNode(i);
    }
    Graph[0]->neighbors.push_back(Graph[2]);
    Graph[0]->neighbors.push_back(Graph[4]);
    Graph[1]->neighbors.push_back(Graph[0]);
    Graph[1]->neighbors.push_back(Graph[2]);
    Graph[2]->neighbors.push_back(Graph[3]);
    Graph[3]->neighbors.push_back(Graph[4]);
    Graph[4]->neighbors.push_back(Graph[3]);

    cout << "graph:" << endl;
    for(int i = 0;i < MAX_N;i++)
    {
        cout << "label:" << i << " ";
        for(int j = 0;j < Graph[i]->neighbors.size();j++)
        {
            cout << Graph[i]->neighbors[j]->label;
        }
        cout << endl;
    }

    for(int i = 0;i < MAX_N;i++)
    {
        delete Graph[i];
    }
}
