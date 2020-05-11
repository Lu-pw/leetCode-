#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <set>

using namespace std;

//https://leetcode-cn.com/problems/word-ladder-ii/
//���126
struct Qitem
{
    string node;//�����ڵ�
    int parent_pos;//ǰ���ڵ��ڶ����е�λ��
    int step;//���ﵱǰ�ڵ㲽��
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
        int cnt = 0;//��¼word1��word2������ַ��ĸ���
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
                       vector<Qitem> &Q,//ʹ��vectorʵ�ֵĶ��У��ɱ���������Ϣ
                       vector<int> &end_word_pos)//�յ�end����λ�õ��±�
    {
        map<string,int> visit;//�����ʣ�������
        int min_step = 0;//����endWord����С����
        Q.push_back(Qitem(beginWord,-1,1));//��ʼ����ǰ��Ϊ-1
        visit[beginWord] = 1;//�����ʼ���ʲ���Ϊ1
        int front = 0;//����ͷָ�룬ָ��vector��ʾ�Ķ���ͷ
        while(front != Q.size())//frontָ��Q.size(),��vectorβ��ʱ������Ϊ��
        {
            const string &node = Q[front].node;
            int step = Q[front].step;//ȡ��ͷԪ��
            if(min_step != 0 && step > min_step)//step>min_step���������е��յ��·���������
            {
                break;
            }
            if(node == endWord)//���������ʱ����¼�����յ����С����
            {
                min_step = step;
                end_word_pos.push_back(front);
            }
            const vector<string> &neighbors = graph[node];
            for(int i = 0; i < neighbors.size(); i++)
            {
                //�ڵ�δ�����ʻ���һ��·��
                if(visit.find(neighbors[i]) == visit.end()|| visit[neighbors[i]] == step + 1)
                {
                    Q.push_back(Qitem(neighbors[i],front,step + 1));
                    visit[neighbors[i]] = step + 1;//��ǵ����ٽӵ����С����
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
