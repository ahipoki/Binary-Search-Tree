#include <iostream>
#include <cstring>
#include "BST.h"

using namespace std;

Node* BST::Insert(Node* node, int key){
  if (node == NULL){
    node = new Node;
    node->Key = key;
    node->Left = NULL;
    node->Right = NULL;
    node->Parent = NULL;
  }
  else if (node->Key->Right = Insert(node->Right, key){
    node->Right->Parent = node;
  }
  else{
    node->Left = Insert(node->Left, key);
    node->Left->Parent = node;
  }
  return node;
}

void BST::PrintTreeInOrder(Node* node){
  if (node == NULL){
    return;
  }
  PrintTreeInOrder(node->Left);
  cout<<Key->Right;
}
