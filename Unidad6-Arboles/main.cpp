// Binary Tree in C++

#include <stdlib.h>

#include <iostream>
#include <string>

using namespace std;

struct node {
  char* _char;
  struct node *left;
  struct node *right;
};

// New node creation
struct node* newNode(char* c) {
  node* n = new node();

  n->_char = c;

  n->left = NULL;
  n->right = NULL;
  return (n);
}

void insert( char* ch,node *&current){
    if(current == NULL)
    {
      
        node *newnode = newNode(ch);
        current=newnode;
    }
    else{
        if(ch < current->_char){
            insert(ch,current->left);

        }
        else{
            insert(ch,current->right);
        }
    }
    return;
}

// Traverse Preorder
void traversePreOrder(struct node *temp) {
  if (temp != NULL) {
    cout << " " << temp->_char;
    traversePreOrder(temp->left);
    traversePreOrder(temp->right);
  }
}

// Traverse Inorder
void traverseInOrder(struct node *temp) {
  if (temp != NULL) {
    traverseInOrder(temp->left);
    cout << " " << temp->_char;
    traverseInOrder(temp->right);
  }
}

// Traverse Postorder
void traversePostOrder(struct node *temp) {
  if (temp != NULL) {
    traversePostOrder(temp->left);
    traversePostOrder(temp->right);
    cout << " " << temp->_char;
  }
}

int main() {

  char list[] {'G','B', 'Q', 'A', 'C', 'K', 'F', 'P', 'D', 'E', 'R', 'H'};
  node* root = NULL;

  for(int i=0;i < sizeof(list); i++){
    char* ch = &list[i];
    insert(ch, root);

  }


  cout << "preorder traversal: ";
  traversePreOrder(root);
  cout << "\nInorder traversal: ";
  traverseInOrder(root);
  cout << "\nPostorder traversal: ";
  traversePostOrder(root);
}