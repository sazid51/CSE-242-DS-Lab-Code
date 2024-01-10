//Finding the median of a doubly linked list
#include<bits/stdc++.h>
using namespace std;
int len=0;
struct Node
{
    int data;
    Node* prev;
    Node* next;
};
Node* Construct(){
    Node* head=nullptr;
    Node* prev_node=nullptr;
    cout<<"List Constructon:\n";
    while(1){
        int user_data;
        cin>>user_data;
        if(user_data==-1) break;

        Node* cur_node = new Node;
        cur_node->data = user_data;
        cur_node->prev = prev_node;
        cur_node->next = nullptr;
        if(head==nullptr)
            head = cur_node;

        else{
            prev_node->next = cur_node; 
        }    
        prev_node = cur_node;
        len++;
    }
    return head;
}

void MedianValue (Node* cur_node)
{
    for(int i=0;i<len/2;i++)
    {
        cur_node = cur_node->next;
    }
    cout<<cur_node->data<<endl;
}

int main()
{
    Node* head= Construct();
    MedianValue(head);
}