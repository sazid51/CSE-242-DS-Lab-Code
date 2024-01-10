#include<bits/stdc++.h>
using namespace std;

struct Node{
int data;
Node* next;
};

Node* head=nullptr,*tail=nullptr;
void En_queue(int y){


    Node* new_node=new Node;
    new_node->data=y;
    new_node->next=nullptr;

    if(head==nullptr){
        head=new_node;
        tail=new_node;
        new_node->next=head;
    }
    else{
        tail->next=new_node;
        new_node->next=head;
        tail=new_node;
    }


}

void de_queue(){
    if(head==nullptr){

    }
    else if(head==tail){

        head=nullptr;
        tail=nullptr;
    }
    else{
            Node* temp=head;
        head=head->next;
        tail->next=head;
        free(temp);

    }


}

void traverse(){

    if(head==nullptr)return;
 Node* curr_node=head;
 cout << curr_node->data << " ";
  while(curr_node->next!=head){
        cout << curr_node->next->data << " ";
    curr_node=curr_node->next;
 }
 cout << endl;

}



int main()
{
    int in;
    cout << "Enter 1 for enqueue,and the element" << endl;
    cout << "Enter 2 for dequeue" << endl;
    cout << "Enter -1 to stop" << endl;
    while(1){
        cin >> in;
        if(in==-1)break;
        if(in==1){
            int y;
            cin >> y;
            En_queue(y);
        }
        else{
            de_queue();
        }

        cout << "after operating the list" << endl;
        traverse();
    }
}