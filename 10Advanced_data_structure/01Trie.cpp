#include <iostream>
#include <vector>
using namespace std;

#define TRIE_MAX_CHAR_NUM 26

struct TrieNode
{
    TrieNode *child[TRIE_MAX_CHAR_NUM];
    bool is_end;
    TrieNode():is_end(false)
    {
        for(int i = 0; i < TRIE_MAX_CHAR_NUM; i++)
        {
            child[i] = 0;
        }
    }
};

void preorder_trie(TrieNode *node,int layer)
{
    for(int i = 0; i < TRIE_MAX_CHAR_NUM; i++)
    {
        if(node->child[i])
        {
            for(int j = 0; j < layer; j++)
            {
                cout <<"---";
            }
            cout << char(i + 'a');
            if(node->child[i]->is_end)
            {
                cout << "  end!";
            }
            cout << endl;
            preorder_trie(node->child[i],layer+1);
        }
    }
}


//Trie树获取全部单词
void get_all_word_from_trie(TrieNode *node,string &word,
                            vector<string> &word_list)
{
    for(int i = 0; i < TRIE_MAX_CHAR_NUM; i++)
    {
        if(node->child[i])
        {
            word.push_back(char(i + 'a'));
            if(node->child[i]->is_end)
            {
                word_list.push_back(word);
            }
            get_all_word_from_trie(node->child[i],word,word_list);
            word.erase(word.length() - 1,1);
        }
    }
}


//整体功能
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
    };
    void insert(const char *word)
    {
        TrieNode *ptr = &_root;
        while(*word)//*word指针对应的字符
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
    bool search(const char *word)
    {
        TrieNode *ptr = &_root;
        while(*word)
        {
            int pos = *word - 'a';
            if(!ptr->child[pos])
            {
                return false;
            }
            ptr = ptr->child[pos];
            word++;
        }
        return ptr->is_end;
    }

    bool startWith(const char *prefix)
    {
        TrieNode *ptr = &_root;
        while(*prefix)
        {
            int pos = *prefix - 'a';
            if(!ptr->child[pos])
            {
                return false;
            }
            ptr = ptr->child[pos];
            prefix++;
        }
        return true;
    }
    TrieNode *root()
    {
        return &_root;
    }

private:
    TrieNode *new_node()
    {
        TrieNode *node = new TrieNode();
        _node_vec.push_back(node);
        return node;
    }
    vector<TrieNode *> _node_vec;
    TrieNode _root;
};

int main()
{
    TrieNode root;
    TrieNode n1;
    TrieNode n2;
    TrieNode n3;
    root.child['a' - 'a'] = &n1;
    root.child['b' - 'a'] = &n1;
    root.child['c' - 'a'] = &n1;

    TrieNode n4;
    TrieNode n5;
    TrieNode n6;
    n1.child['d' - 'a'] = &n4;
    n2.child['e' - 'a'] = &n5;
    n3.child['f' - 'a'] = &n6;

    TrieNode n7;
    TrieNode n8;
    TrieNode n9;
    TrieNode n10;
    n4.child['g' - 'a'] = &n7;
    n4.child['h' - 'a'] = &n8;
    n5.child['i' - 'a'] = &n9;
    n6.child['j' - 'a'] = &n10;
    n7.is_end = true;
    n8.is_end = true;
    n9.is_end = true;
    n10.is_end = true;

    TrieNode n11;
    n7.child['d' - 'a'] = &n11;
    n11.is_end = true;
    preorder_trie(&root,0);


    string word = "";
    vector<string> word_list;
    get_all_word_from_trie(&root,word,word_list);
    for(int i = 0; i < word_list.size(); i++)
    {
        cout <<word_list[i] << " ";
    }
    cout << endl;
    cout << endl;
    cout << endl;


    TrieTree trie_tree;
    trie_tree.insert("abcd");
    trie_tree.insert("abc");
    trie_tree.insert("abd");
    trie_tree.insert("b");
    trie_tree.insert("bcd");
    trie_tree.insert("efg");
    cout << "preorder_trie:" <<endl;
    preorder_trie(trie_tree.root(),0);
    cout << endl;
    cout << endl;
    cout << "Search:" << endl;
    cout << boolalpha << trie_tree.search("abc") <<endl;
    cout << boolalpha << trie_tree.search("abcd")<<endl;
    cout << boolalpha << trie_tree.search("bc")<<endl;
    cout << boolalpha << trie_tree.search("b")<<endl;
    cout << endl;
    cout << boolalpha<<trie_tree.startWith("ab")<<endl;
    cout << boolalpha<<trie_tree.startWith("abc")<<endl;
    cout << boolalpha<<trie_tree.startWith("bc")<<endl;
    cout << boolalpha<<trie_tree.startWith("fg")<<endl;
    return 0;
}
