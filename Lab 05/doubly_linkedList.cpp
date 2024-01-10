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
        cur_node->data = user_data;
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

void RecTraverse(Node* cur_node){
    if(cur_node==nullptr) return;
    cout<<cur_node->prev<<" "<<cur_node->data<<" "<<cur_node->next<<endl;
    return RecTraverse(cur_node->next);
}

void ItTraverse(Node* cur_node){
    while(cur_node!=nullptr){
        cout<<cur_node->prev<<"\t"<<cur_node->data<<"\t"<<cur_node->next<<endl;
        cur_node = cur_node->next;
    }
}

Node* InsertInSorted (Node* head, int new_data)
{
    Node* cur_node = head;
    Node* new_node=new Node;
    new_node->data = new_data;
    new_node->prev = nullptr;
    new_node->next = nullptr;   
    // Node* cur_node = new Node;
    // cur_node->prev=nullptr;
    // cur_node->next = nullptr;

    if(cur_node == nullptr) head = new_node;

    else if(cur_node->data > new_data){
        new_node->next= cur_node;
        cur_node->prev = new_node;
        head = new_node;
    }

    else{
        Node* prev_node = nullptr;
        while(cur_node != nullptr && cur_node->data < new_data){
            prev_node = cur_node;
            cur_node = cur_node->next;
        }
        if(cur_node != nullptr) cur_node->prev = new_node;
        new_node->next = cur_node;
        prev_node->next = new_node;
        new_node->prev = prev_node;
    }
    return head;
}

int main()
{
    //Node* head=Construct();
    //RecTraverse(head);
    //ItTraverse(head);'
    Node* head = nullptr; 
    while (1){
        int n;
        cin>>n;
        if(n==-1) break;
        head = InsertInSorted(head, n);
        ItTraverse(head);
        cout<<"----"<<endl;
    }
    
}