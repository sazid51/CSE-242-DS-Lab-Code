//Performing insertion/deletion operation in doubly linked list
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* prev;
    Node* next;
};

Node* InsertBeginning(Node* head, int x)
{
    Node* new_node = new Node;
    new_node->data = x;
    new_node->prev = nullptr;
    new_node->next = nullptr;
    if(head==nullptr) head = new_node;

    else{
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
    return head;
}

Node* InsertEnd(Node* head,int x){
    Node* new_node = new Node;
    new_node->data = x;
    new_node->prev = nullptr;
    new_node->next = nullptr;
    if(head==nullptr) head = new_node;

    else{
        Node* cur_node = head;
        while(cur_node->next != nullptr)
            cur_node = cur_node->next;

        new_node->prev = cur_node;
        cur_node->next = new_node;
    }
    return head;
}

void InsertAfter(Node* cur_node,int p, int x)
{
    if(p==1) {
        Node* new_node = new Node;
        new_node->data=x;
        new_node->next=cur_node->next;
        new_node->prev=cur_node;
        cur_node->next->prev = new_node;
        cur_node->next=new_node;
    }

    else 
        InsertAfter(cur_node->next,p-1, x);
}

Node* Delete(Node* head, int key)
{
    if(head == nullptr) cout<<"List is Empty\n";
    else if(head->data == key)
    {
        Node* temp = head;
        head = temp->next;
        temp->next->prev = nullptr;
        free(temp); 
    }
    else{
        Node* cur_node = head;
        while(cur_node->data != key)
            cur_node = cur_node->next;

        Node* temp = cur_node;
        if(cur_node->next != nullptr) cur_node->next->prev = cur_node->prev;
        temp->prev->next = cur_node->next;
        free(temp);
    }
    return head;
}

void ItTraverse(Node* cur_node){
    while(cur_node!=nullptr){
        cout<<cur_node->prev<<"\t"<<cur_node->data<<"\t"<<cur_node->next<<endl;
        cur_node = cur_node->next;
    }
    cout<<"----"<<endl;
}

int main()
{
    Node* head = nullptr;
    head = InsertBeginning(head,5);
    head = InsertEnd(head, 8);
    head = InsertBeginning(head, 2);
    InsertAfter(head, 2, 12);
    ItTraverse(head);
    head = Delete(head, 2);
    ItTraverse(head);
    head = Delete(head, 8);
    ItTraverse(head);
}