#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <set>

using namespace std;

//https://leetcode-cn.com/problems/word-ladder-ii/
//题号126
struct Qitem
{
    string node;//搜索节点
    int parent_pos;//前驱节点在队列中的位置
    int step;//到达当前节点步数
    Qitem(string _node,int _parent_pos,int _step):
        node(_node),parent_pos(_parent_pos),step(_step) {}
};

class solution
{
public:
    vector<vector<string>> ladderLength(string beginWord,
                     string endWord,vector<string> &wordList)
    {
        map<string,vector<string>> graph;
        construct_graph(beginWord,wordList,graph);
        vector<Qitem> Q;
        vector<int> end_word_pos;
        BFS_graph(beginWord,endWord,graph,Q,end_word_pos);
        vector<vector<string>> result;
        for(int i = 0;i < end_word_pos.size();i++)
        {
            int pos = end_word_pos[i];
            vector<string> path;
            while(pos != -1)
            {
                path.push_back(Q[pos].node);
                pos = Q[pos].parent_pos;
            }
            result.push_back(vector<string>());
            for(int j = path.size() - 1;j >= 0;j--)
            {
                result[i].push_back(path[j]);
            }
        }
        return result;
    }

    bool connect(const string &word1,const string &word2)
    {
        int cnt = 0;//记录word1与word2不相等字符的个数
        for(int i = 0; i < word1.length(); i++)
        {
            if(word1[i] != word2[i])
            {
                cnt++;
            }
        }
        return cnt == 1;
    }

    void construct_graph(string &beginWord,vector<string>& wordList,
                         map<string,vector<string>> &graph)
    {
        int has_begin_word = 0;
        for(int i = 0;i < wordList.size();i++)
        {
            if(wordList[i] == beginWord)
            {
                has_begin_word = 1;
            }
            graph[wordList[i]] = vector<string> ();
        }
        for(int i = 0;i < wordList.size();i++)
        {
            for(int j = i + 1;j < wordList.size();j++)
            {
                if(connect(wordList[i],wordList[j]))
                {
                    graph[wordList[i]].push_back(wordList[j]);
                    graph[wordList[j]].push_back(wordList[i]);
                }
            }
            if(has_begin_word == 0 && connect(beginWord,wordList[i]))
            {
                graph[beginWord].push_back(wordList[i]);
            }
        }
    }

    void BFS_graph(string &beginWord,string &endWord,
                   map<string,vector<string>> &graph,
                       vector<Qitem> &Q,//使用vector实现的队列，可保存所有信息
                       vector<int> &end_word_pos)//终点end所在位置的下标
    {
        map<string,int> visit;//《单词，步数》
        int min_step = 0;//到达endWord的最小步数
        Q.push_back(Qitem(beginWord,-1,1));//起始单词前驱为-1
        visit[beginWord] = 1;//标记起始单词步数为1
        int front = 0;//队列头指针，指向vector表示的队列头
        while(front != Q.size())//front指向Q.size(),即vector尾部时，队列为空
        {
            const string &node = Q[front].node;
            int step = Q[front].step;//取队头元素
            if(min_step != 0 && step > min_step)//step>min_step，代表所有到终点的路径搜索完成
            {
                break;
            }
            if(node == endWord)//搜索到结果时，记录到达终点的最小步数
            {
                min_step = step;
                end_word_pos.push_back(front);
            }
            const vector<string> &neighbors = graph[node];
            for(int i = 0; i < neighbors.size(); i++)
            {
                //节点未被访问或另一条路径
                if(visit.find(neighbors[i]) == visit.end()|| visit[neighbors[i]] == step + 1)
                {
                    Q.push_back(Qitem(neighbors[i],front,step + 1));
                    visit[neighbors[i]] = step + 1;//标记到达临接点的最小步数
                }
            }
            front++;
        }
    }
};


int main()
{
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList;
    wordList.push_back("hot");
    wordList.push_back("dot");
    wordList.push_back("dog");
    wordList.push_back("lot");
    wordList.push_back("log");
    wordList.push_back("cog");
    solution s01;
    vector<vector<string>> result = s01.ladderLength(beginWord,endWord,wordList);
    for(int i = 0;i < result.size();i++)
    {
        for(int j = 0;j < result[i].size();j++)
        {
            cout << result[i][j] <<" ";
        }
        cout << endl;
    }
}
