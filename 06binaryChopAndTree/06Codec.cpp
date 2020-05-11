#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr) {}
};

class Codec
{
public:
    string serialize(TreeNode *root)
    {
        string data;
        BST_preorder(root,data);
        return data;
    }
    TreeNode* deserialize(string data)
    {
        if(data.length() == 0)
        {
            return NULL;
        }
        vector<TreeNode*> node_vec;
        int val = 0;
        for(int i = 0; i < data.size(); i++)
        {
            if(data[i] == '#')
            {
                node_vec.push_back(new TreeNode(val));
                val = 0;
            }
            else
            {
                val = val * 10 + (data[i] - '0');
            }
        }
        for(int i = 1; i < node_vec.size(); i++)
        {
            BST_insert(node_vec[0],node_vec[i]);
        }
        return node_vec[0];
    }
    void change_int_to_string(int val,string &str_val)
    {
        string tmp;
        while(val)
        {
            tmp += val%10 + '0';
            val = val / 10;
        }
        for(int i = tmp.length()-1; i >= 0; i--)
        {
            str_val += tmp[i];
        }
        str_val += "#";
    }

    void BST_preorder(TreeNode *node,string &data)
    {
        if(!node)
        {
            return;
        }
        string str_val;
        change_int_to_string(node->val,str_val);
        data += str_val;
        BST_preorder(node->left,data);
        BST_preorder(node->right,data);
    }

    void BST_insert(TreeNode *node,TreeNode *insert_node)
    {
        if(insert_node->val < node->val)
        {
            if(node->left)
            {
                BST_insert(node->left,insert_node);
            }
            else
            {
                node->left = insert_node;
            }
        }
        else
        {
            if(node->right)
            {
                BST_insert(node->right,insert_node);
            }
            else
            {
                node->right = insert_node;
            }
        }
    }
};


void preorder(TreeNode *root,int layer)
{
    if(!root)
    {
        return;
    }
    for(int i = 0; i < layer;i++)
    {
        cout << "--";
    }
    cout << root->val << endl;
    preorder(root->left,layer+1);
    preorder(root->right,layer+1);
}

int main()
{
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(3);
    TreeNode d(4);
    TreeNode e(5);
    TreeNode f(6);
    a.left = &b;
    a.right = &c;
    b.left = &d;
    c.left = &e;
    c.right = &f;

    Codec s01;
    string ret = s01.serialize(&a);
    cout << ret << endl;
    TreeNode *p = s01.deserialize(ret);
    preorder(p,0);

}
