#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
};

void Duplicate(Node* root)
{
    Node* cur_node;
    cur_node=root;
    Node* next_node;
    while(cur_node != nullptr) {
        next_node=cur_node->next;
        while(next_node != nullptr) {
            if(cur_node->data == next_node->data) 
            {
                Node* temp = next_node;
                next_node = next_node->next;
                delete (temp);
            }
            else
                next_node = next_node->next;
        }
        cur_node = cur_node->next;
    }
}