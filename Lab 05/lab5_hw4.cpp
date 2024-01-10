//Traversing a circular linked list from any given random node
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* next;
};

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
        cur_node->next = head;
        if(head==nullptr)
            head = cur_node;

        else{
            prev_node->next = cur_node; 
        }
        prev_node = cur_node;
    }
    return head;
}

void TraverseRandomNode(Node* cur_node)
{
    Node* temp = cur_node;
    cout<<cur_node->data<<" ";
    cur_node=cur_node->next;
    while(cur_node != temp)
    {
        cout<<cur_node->data<<" ";
        cur_node=cur_node->next;
    }
    cout<<endl;
}

int main()
{
    Node* head = Construct();
    TraverseRandomNode(head->next->next);

}