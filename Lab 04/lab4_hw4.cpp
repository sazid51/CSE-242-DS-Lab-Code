//Implementing Stack using Linked List
#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
};
Node* Top=nullptr;

//Taking input in Stack
void push(int x)
{
    Node* new_node = new Node;
    new_node->data = x;
    new_node->next = nullptr;
    if(Top == nullptr)
        Top = new_node;
    else{
        new_node->next = Top;
        Top = new_node;
    }
}

//Removing top element of Stack
void pop ()
{
    if(Top == nullptr) cout<<"Stack is Eempty\n";
    else {
        Node* temp = Top;
        Top = temp->next;
        temp->next = nullptr;
        free(temp);
    }
}

//To display all the elements of stack
void display()
{
    Node* cur_node = Top;
    while(cur_node!=nullptr)
    {
        cout<<cur_node->data<<" ";
        cur_node = cur_node->next;
    }
    cout<<endl;
}

//To show the top element of stack
void top()
{
    if(Top==nullptr) cout<<"Stack is Empty\n";
    else 
        cout<<Top->data<<endl;
}
int main()
{
    push(2);
    push(6);
    push(3);
    push(9);
    display();
    pop();
    top();
    pop();
    top();
    display();
}