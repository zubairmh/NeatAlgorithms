#include <bits/stdc++.h>

using namespace std;

struct Node {
  Node *left;
  Node *right;
  int val;
};

Node *CreateNode(int val) {
  Node *tree = new Node;
  tree->val = val;
  return tree;
}

Node *Insert(Node *tree, int val) {
  if (tree == NULL) {
    return CreateNode(val);
  }
  if (val < tree->val) {
    tree->left = Insert(tree->left, val);
  } else if (val >= tree->val) {
    tree->right = Insert(tree->right, val);
  }

  return tree;
}

void BFS(Node *tree) {
    list<Node*> queue; // Initialize Queue
    queue.push_front(tree);
    while(!queue.empty()) {
        Node *t=queue.front();
        cout<<t->val<<" ";
        queue.pop_front(); // Dequeue first element
        if(t->left) {
            queue.push_back(t->left); // Push Left Subtree
        } 
        if(t->right) {
            queue.push_back(t->right); // Push Right Subtree
        }
        
    }    
}

void Inorder(Node *tree) {
  if (tree == NULL) {
    return;
  }

  if (tree->left) {
    Inorder(tree->left);
  }
  cout << tree->val;
  if (tree->right) {
    Inorder(tree->right);
  }
}

void Postorder(Node *tree) {
  if (tree == NULL) {
    return;
  }

  if (tree->left) {
    Postorder(tree->left);
  }
  if (tree->right) {
    Postorder(tree->right);
  }
  cout << tree->val;
}

void Preorder(Node *tree) {
  if (tree == NULL) {
    return;
  }
  cout << tree->val;
  if (tree->left) {
    Preorder(tree->left);
  }
  if (tree->right) {
    Preorder(tree->right);
  }
}
int main() {
  Node *tree = CreateNode(6);
  Insert(tree, 2);
  Insert(tree, 4);
  Insert(tree, 8);
  Insert(tree, 9);
  Insert(tree, 7);
  Insert(tree, 5);
  Inorder(tree);
  cout << endl;
  Postorder(tree);
  cout << endl;
  Preorder(tree);
  cout<<endl;
  BFS(tree);
}