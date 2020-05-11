#include <iostream>
#include <vector>

using namespace std;

#define TRIE_MAX_CHAR_NUM 26

struct TrieNode
{
    bool is_end;
    TrieNode *child[TRIE_MAX_CHAR_NUM];
    TrieNode():is_end(false)
    {
        for(int i = 0; i < TRIE_MAX_CHAR_NUM; i++)
        {
            child[i] = 0;
        }
    }
};

class TrieTree
{
public:
    TrieTree() {}
    ~TrieTree()
    {
        for(int i = 0; i < _node_vec.size(); i++)
        {
            delete _node_vec[i];
        }
    }
    void insert(const char *word)
    {
        TrieNode *ptr = &_root;
        while(*word)
        {
            int pos = *word - 'a';
            if(!ptr->child[pos])
            {
                ptr->child[pos] = new_node();
            }
            ptr = ptr->child[pos];
            word++;
        }
        ptr->is_end = true;
    }
    bool search_trie(TrieNode *node,const char *word)
    {
        if(node->is_end)
        {
            if(*word == '\0')
            {
                return true;
            }
            return false;
        }
        if(*word == '.')
        {
            for(int i = 0; i < TRIE_MAX_CHAR_NUM; i++)
            {
                if(node->child[i]&&search_trie(node->child[i],word+1))
                {
                    return true;
                }
            }
        }
        else
        {
            if(*word == '\0')
            {
                return false;
            }
            int pos = *word - 'a';
            if(node->child[pos] && search_trie(node->child[pos],word+1))
            {
                return true;
            }
        }
        return false;
    }
    TrieNode *root()
    {
        return &_root;
    }
private:
    TrieNode _root;
    vector<TrieNode *> _node_vec;
    TrieNode *new_node()
    {
        TrieNode *node = new TrieNode();
        _node_vec.push_back(node);
        return node;
    }

};

class WordDictionay
{
public:
    WordDictionay() {}
    void addWord(string word)
    {
        _trie_tree.insert(word.c_str());
    }
    bool search(string word)
    {
        //使用trie树对字符串进行存储与查找，
        //对于存储（添加单词），即为规范的trie添加单词的方法
        //思考出现'.'时，如何进行搜索；
        return _trie_tree.search_trie(_trie_tree.root(),word.c_str());
    }
private:
    TrieTree _trie_tree;
};

int main()
{
    WordDictionay word_dictionary;
    word_dictionary.addWord("bad");
    word_dictionary.addWord("dad");
    word_dictionary.addWord("mad");
    cout << boolalpha << word_dictionary.search("pad") << endl;
    cout << boolalpha << word_dictionary.search("bad") << endl;
    cout << boolalpha << word_dictionary.search(".ad") << endl;
    cout << boolalpha << word_dictionary.search("b..") << endl;
    cout << boolalpha << word_dictionary.search("b.") << endl;
    return 0;
}

