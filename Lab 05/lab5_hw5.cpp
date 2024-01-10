//Implementing queue using circular linked list
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* next;
};
Node* Top=nullptr;
Node* last = nullptr;

void push(int x){
    Node* new_node = new Node;
    new_node->data = x;
    new_node->next = Top;
    if(Top==nullptr)
        Top = new_node;

    else{
        last->next = new_node; 
    }
    last = new_node;
}

void pop ()
{
    if(Top == nullptr) cout<<"Queue is Empty\n";
    else {
        Node* temp = Top;
        Top = temp->next;
        if(Top == nullptr) last = nullptr;
        else last->next = Top;
        free(temp);
    }
}

void display()
{
    if(Top==nullptr) return;
    cout<<Top->data<<" ";
    Node* cur_node = Top->next;
    while(Top != cur_node)
    {
        cout<<cur_node->data<<" ";
        cur_node = cur_node->next;
    }  
    cout<<endl;
}

int main()
{
    push(2);
    push(6);
    push(3);
    push(9);
    display();
    pop();
    pop();
    display();
}