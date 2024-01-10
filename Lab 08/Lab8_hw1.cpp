#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *right, *left;
};

void Inorder(Node* root)
{
    if(root == nullptr) return;

    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}

Node* Construct(Node* root, int data)
{
    if(root == nullptr){ 
        Node* new_node = new Node;
        new_node->data = data;
        new_node->left = nullptr;
        new_node->right = nullptr;
        root = new_node;
    }

    else if(data>root->data)
        root->right= Construct(root->right, data);

    else 
        root->left = Construct(root->left, data);
    
    return root;
}

Node* GetMin(Node* cur_node)
{
    while(cur_node->left !=nullptr)
        cur_node = cur_node->left;
    
    return cur_node;
}

Node* Delete(Node* root, int data)
{
    if(root==nullptr) return root;
    else if(data < root->data) 
        root->left = Delete(root->left, data);
    else if(data > root->data)
        root->right = Delete(root->right, data);
    else
    {
        //Deletion for zero child
        if(root->left==nullptr && root->right==nullptr)
        {
            Node* temp=root;
            root = nullptr;
            delete temp;
        }
        //Deletion for 1 child
        else if(root->left==nullptr)
        {
            Node* temp = root;
            root = root->right;
            delete temp;
        }
        else if(root->right==nullptr)
        {
            Node* temp = root;
            root = root->left;
            delete temp;
        }
        //Deletion for 2 child
        else
        {
            Node* temp = GetMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }
    return root;
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

        root = Construct(root, new_data);
    }
    cout<<"Before Deletion the Tree is: ";
    Inorder(root);

    int x;
    cout<<"\nEnter number to be deleted: ";
    cin>>x;
    root=Delete(root,x);
    cout<<"After Deletion the tree is: ";
    Inorder(root);
    cout<<endl;

    cout<<"\nEnter number to be found: ";
    cin>>x;
    if(Search(root, x)) cout<<"Found"<<endl;
    else cout<<"Not found"<<endl;
}
