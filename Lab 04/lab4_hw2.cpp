//Insertion in Linked List in Sorted Order
#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
};

Node* InsertInSorted (Node* head, int new_data)
{
    Node* cur_node = head;
    Node* new_node=new Node;
    new_node->data = new_data;
    new_node->next = nullptr; 

    if(cur_node == nullptr) head = new_node;

    else if(cur_node->data > new_data){
        new_node->next= cur_node;
        head = new_node;
    }

    else{
        Node* prev_node = nullptr;
        while(cur_node != nullptr && cur_node->data < new_data){
            prev_node = cur_node;
            cur_node = cur_node->next;
        }
        new_node->next = cur_node;
        prev_node->next = new_node;
    }
    return head;
}

void Traverse(Node* cur_node)
{
    cout<<"List Traversing:"<<endl;
    while(cur_node != nullptr){
        cout<<cur_node->data<<" "<<cur_node->next<<endl;
        cur_node = cur_node->next;
    }
}

int main()
{
    Node* head = nullptr; 
    while (1){
        int n;
        cin>>n;
        if(n==-1) break;
        head = InsertInSorted(head, n);
        Traverse(head);
        cout<<"----"<<endl;
    }
    
}

