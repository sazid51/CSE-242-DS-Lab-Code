#include<bits/stdc++.h>
using namespace std;

struct Node {
  int info, left, right;
};

Node node[100];

/// preorder: cur_node -> left -> right
/// inorder: left -> cur_node -> right
/// postrder: left -> right -> cur_node
void Preorder(int cur_node) {
  if (cur_node == -1) {
    return;
  }
  cout << node[cur_node].info << endl;
  Preorder(node[cur_node].left);
  Preorder(node[cur_node].right);
}

///Odd_id => Inorder, Even_id => Postorder

int main() {
  int i, j, k;
  int n;
  cin >> n;
  for (i = 0; i < n; ++i) {
    cin >> node[i].info >> node[i].left >> node[i].right;
  }
  int root = 0;
  Preorder(root);
}