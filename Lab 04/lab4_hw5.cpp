//Implementing Queue using Linked List
#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
};
Node* Top=nullptr;

//Inserting element at last position of the Queue 
void push(int x)
{
    Node* new_node = new Node;
    Node* cur_node = Top;
    new_node->data = x;
    new_node->next = nullptr;
    if(Top==nullptr)
        Top = new_node;
    else{
        while(cur_node->next != nullptr){
            cur_node = cur_node->next;
        }
        cur_node->next = new_node;
    }
}

//Removing top element of Queue
void pop ()
{
    if(Top == nullptr) cout<<"Queue is Empty\n";
    else {
        Node* temp = Top;
        Top = temp->next;
        temp->next = nullptr;
        free(temp);
    }
}

//To display all the elements of Queue
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