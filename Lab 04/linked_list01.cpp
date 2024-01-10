#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int n;
struct Node{
    int data;
    Node* next;
};

//List construction
Node* Construct(){
    Node* head=nullptr;
    Node* prev_node;
    cout<<"List Constructon:\n";
    while(1){
        int user_data;
        cin>>user_data;
        if(user_data==-1) break;

        Node* cur_node = new Node;
        cur_node->data = user_data; /* (*cur_node).data = user_data */
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

//List Traversing
void Traverse(Node* cur_node)
{
    cout<<"List Traversing:"<<endl;
    while(cur_node != nullptr){
        cout<<cur_node->data<<" "<<cur_node->next<<endl;
        cur_node = cur_node->next;
    }
}

void RecTraverse(Node* cur_node)
{
    if(cur_node==nullptr) return;
    cout<<cur_node->data<<endl;
    RecTraverse(cur_node->next);
}

void InsertAfter(Node* cur_node, int p, int x)
{
    if(p==1) {
        Node* new_node = new Node;
        new_node->data=x;
        new_node->next=cur_node->next;
        cur_node->next=new_node;
    }

    else 
        InsertAfter(cur_node->next, p-1, x);
}

Node* Reverse(Node* cur_node, Node* prev_node=nullptr){
    if(cur_node==nullptr)
        return prev_node;

    else {
        Node* next_node = cur_node->next;
        cur_node->next=prev_node;
        //prev_node = cur_node;
        return Reverse(next_node, cur_node);
    }
}

int main()
{
    Node* head = Construct();
    Traverse(head); 
    //RecTraverse(head);
    InsertAfter(head,2,7); //Insert a value after 2 node
    cout<<"Linked List after insertion:\n";
    Traverse(head);
    head = Reverse(head);
    cout<<"List after Reverse:\n";
    Traverse(head);

}