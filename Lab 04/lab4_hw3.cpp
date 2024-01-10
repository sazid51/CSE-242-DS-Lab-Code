//Checking a list palindorme or not
#include<bits/stdc++.h>
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
        cur_node->data = user_data;
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

void IsPalindrome(Node* cur_node)
{
    vector<int> v1,v2;
    while(cur_node != nullptr){
        v1.push_back(cur_node->data);
        cur_node = cur_node->next;
    }
    v2=v1;
    reverse(v2.begin(), v2.end());
    if(v1==v2) cout<<"The list is Palindrome\n";
    else cout<<"The list is not Palindrome\n";
}

int main()
{
    Node* head = Construct();
    IsPalindrome(head);
}