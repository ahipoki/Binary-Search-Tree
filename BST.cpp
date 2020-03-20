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

void BST::PrintTreeInOrder(){
  PrintTreeInOrder(head, 0);
}

void BST::PrintTreeInOrder(Node* node, int d){
  if (!node){
    return;
  }
  if (node->getLeft()){
    PrintTreeInOrder(node->getLeft(), d+1);
  }
}

bool BST::Search(int node){
  return Search(head, node);
}

bool BST::Search(Node* node, int key){
  if (!node){
    return false;
  }
  if (node->getKey() == key){
    return true;
  }
  if (key < node->getKey()){
    if (node->getLeft() = NULL){
      return false;
    }
    return Search(node->getLeft(), key);
  }
  else{
    if (node->getRight() == NULL){
      return false;
    }
    return Search(node->getRight(), key);
  }
}

void BST::deleteNode(int node){
  if (deleteNode(head, node)){
    cout<<"Node deleted"<<endl;
  }
}

bool BST::deleteNode(Node* &node, int key) {
  if (node == NULL) {               //We have not found the node, return false
    cout << "The tree is empty or that node was not found" << endl;
    return false;
  }
  //Node to delete found
  if (node->getKey() == key) {    //We have found the node, now separate based on how many children
    if (node->getLeft() == NULL && node->getRight() == NULL) { //0 children
      if (node->getParent() == NULL) { //If this is the root node, delete it, and set head to null
	    Node* temp = node;
	    node = NULL;
	    delete temp;
	    return true;
      }
      if (node == node->getParent()->getLeft()){
          node->getParent()->setLeft(NULL); //Otherwise reconfigure parent's child pointer
      }
      else{
          node->getParent()->setRight(NULL);
      }
      delete node;
    }
    else if (node->getLeft() == NULL) { //right child
      if (node->getParent() == NULL) {  //if root node, just set this to the right node, and reconfigure parent pointer
	    Node* temp = node;
	    node = node->getRight();
	    node->setParent(NULL);
	    delete temp;
	    return true;
      }
      Node* Right = node->getRight();     
      if (node == node->getParent()->getLeft()){
          node->getParent()->setLeft(Right); //Point the parent's child pointer to new child
      }
      else node->getParent()->setRight(Right);
      Right->setParent(node->getParent());                                       //Re set the parent pointer
      delete node;
    }
    else if (node->getRight() == NULL) { //left child                  //same thing as the right child
      if (node->getParent() == NULL) {
	    Node* temp = node;
	    node = node->getLeft();
	    node->setParent(NULL);
	    delete temp;
	    return true;
      }
      Node* Left = node->getLeft();
      if (node == node->getParent()->getLeft()){
          node->getParent()->setLeft(Left); //Point the parent's child pointer to new child
      }
      else{
          node->getParent()->setRight(Left);
      }
      Left->setParent(node->getParent());
      delete node;
    }
    else{ //2 children
      //Get inorder successor (only called on upper nodes, so don't need to deal with inorder succ. for leaves)
      Node* temp = node->getRight(); //Inorder successor for not-leaves is one right then as many left as possible
      while (temp->getLeft()) {
	    temp = temp->getLeft();
      }
      int value = temp->getKey(); //Delete the inorder succ., then set the temps value to this
      deleteNode(temp, key);
      
      //Swap values as normal
      node->setKey(temp->getKey()); //set the value of this node to inorder succ.
    }
    return true; //We deleted it so return true
  }
  if (key < node->getKey()) { //If value we are looking for is less than this value then go left
    if (node->getLeft() == NULL) { //If there is nothing to the left the value we are looking for doesn't exist
      cout << "Node not found" << endl;
      return false;
    }
    Node* t = node->getLeft();
    return deleteNode(t, key); //Call deletenode on left node
  }
  else {                     //If value we are looking for is more than this value go right
    if (node->getRight() == NULL) { //Same as left
      cout << "Node not found" << endl;
      return false;
    }
    Node* t = node->getRight();
    return deleteNode(t, key);
  }
}

//public display function
void BST::PrintTreeInOrder() {
  PrintTreeInOrder(head, 0); //call private display function
}

//private display function
void BST::PrintTreeInOrder(Node* node, int d) { //inorder print of bst
  if(!node) return; //empty tree
  if (node->getLeft()){ 
    displayTree(h->getLeft(), d+1);
  }
  for (int i = 0; i < d; i++){
    cout << "   ";
  }
  cout<<node->getKey()<<endl;
  if (node->getRight()){
    PrintTreeInOrder(node->getRight(), d+1);
  }
}

//public search function
bool BST::Search(int node) {
  return Search(head, node);
}

//private recursive search function
bool BST::Search(Node* node, int key) {
  if (!node) return false; //empty tree
  if (node->getKey() == key){
    return true; //Match
  }
  if (key < node->getKey()) {             //less, go left
    if (node->getLeft() == NULL){
      return false;   //node not found, false
    }
    return Search(node->getLeft(), key);    //go left
  }
  else{                                 //greater, go right
    if (node->getRight() == NULL){
      return false;  //node not found, false
    }
    return Search(node->getRight(), key);   //go right
  }
}

//destructor
BST::~BST() { //Repeatedly call delete on head until tree is gone
  while (head){ //Delete tree
    deleteNode(head, head->getKey());
  }
