#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* right;
    Node* left;
};

void MergeNode(Node* root, Node* cur_node)
{
    if(root->data < cur_node->data)
    {
        if( root->right == nullptr)
        {
            root->right = cur_node;
            return;
        }
        else 
            MergeNode(root->right, cur_node);
    }

    else 
    {
        if(root->left == nullptr)
        {
            root->left = cur_node;
            return;
        }
        else 
            MergeNode(root->left, cur_node);
    }
}
void InOrder(Node* root)
{
    if(root == nullptr) return;

    InOrder(root->left);
    cout<<root->data<<" ";
    InOrder(root->right);
}

void PreOrder(Node* root)
{
    if(root == nullptr) return;

    cout<<root->data<<" ";
    PreOrder(root->left);
    PreOrder(root->right);
}

void PostOrder(Node* root)
{
    if(root == nullptr) return;

    PostOrder(root->left);
    PostOrder(root->right);
    cout<<root->data<<" ";
}

bool Search(Node *root,int val)
{
    if(root==nullptr)
    {
        return false;
    }
    else  if(root->data==val)
    {
        return true;
    }

    else if(root->data>val)
        return Search(root->left,val);
    else
        return Search(root->right,val);
}

int main()
{
    Node* root = nullptr;
    while(1)
    {
        int new_data;
        cin>>new_data;
        if(new_data==-1) break;
        Node* new_node = new Node;
        new_node->data = new_data;
        new_node->right = nullptr;
        new_node->left = nullptr;

        if(root == nullptr) 
            root = new_node;

        else 
            MergeNode(root, new_node);
    }
    InOrder(root);
    cout<<"\n";
    PreOrder(root);
    cout<<"\n";
    PostOrder(root);
    cout<<"\n";

    if(Search(root, 8)) cout<<"Found"<<endl;
    else cout<<"Not found"<<endl;
}
