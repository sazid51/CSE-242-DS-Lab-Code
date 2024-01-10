//Reverse a doubly linked list
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* prev;
    Node* next;
};

//List construction
Node* Construct(){
    Node* head=nullptr;
    Node* prev_node=nullptr;
    cout<<"List Constructon:\n";
    while(1){
        int user_data;
        cin>>user_data;
        if(user_data==-1) break;

        Node* cur_node = new Node;
        cur_node->data = user_data; /* (*cur_node).data = user_data */
        cur_node->prev = prev_node;
        cur_node->next = nullptr;
        if(head==nullptr)
            head = cur_node;

        else{
            prev_node->next = cur_node; 
        }
        
        prev_node = cur_node;

    }
    return head;
}

Node* Reverse(Node* cur_node, Node* prev_node=nullptr){
    if(cur_node==nullptr)
        return prev_node;

    else {
        Node* next_node = cur_node->next;
        cur_node->next = prev_node;
        cur_node->prev = next_node;
        return Reverse(next_node, cur_node);
    }
}

void RecTraverse(Node* cur_node){
    if(cur_node==nullptr) return;
    cout<<cur_node->prev<<" "<<cur_node->data<<" "<<cur_node->next<<endl;
    return RecTraverse(cur_node->next);
}

int main()
{
    Node* head = Construct();
    head = Reverse(head);
    RecTraverse(head);

}

