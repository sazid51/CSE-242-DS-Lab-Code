#include<bits/stdc++.h>
#define ll long long int
using namespace std;
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

void Traverse(Node* cur_node)
{
    cout<<"List Traversing:"<<endl;
    while(cur_node != nullptr){
        cout<<cur_node->data<<" "<<cur_node->next<<endl;
        cur_node = cur_node->next;
    }
}

void IsSorted(Node* cur_node)
{
    int t=0;
    while(cur_node != nullptr){
        if(cur_node->data > (cur_node->next)->data)
        {
            t++;
            break;
        }
        cur_node = cur_node->next;
    }
    if(t==0) cout<<"The List is Sorted\n";
    else cout<<"The lsit is not sorted\n";
}

int main()
{
    Node* head = Construct();
    Traverse(head);
    IsSorted(head);

}