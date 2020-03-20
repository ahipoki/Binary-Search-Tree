#include <iostream>
#include <cstring>
#include "BST.h"

using namespace std;

BST::BST(){
  head = NULL;
}

void BST::Insert(int node){
  Insert(head, node);
  cout<<"You added a node"<<endl;
}

Node* BST::Insert(Node* node, int key){
  if (node == NULL){
    node = new Node(key);
    return;
  }
  else if (key < node->getKey()){
    if (node->getLeft() == NULL){
      node->setLeft(new Node(key));
      node->getLeft()->setParent(node);
      return;
    }
    Node* Left = node->getLeft();
    Insert(Left, key);
    return;
  }
  else{
    if (node->getRight() == NULL){
      node->setRight(new Node(key));
      node->getRight()->setParent(node);
      return;
    }
    Node* Right = node->getRight();
    Insert(Right, key);
    return;
  }
}

void BST::PrintTreeInOrder(Node* node){
  if (node == NULL){
    return;
  }
  PrintTreeInOrder(node->Left);
  cout<<Key->Right;
}
