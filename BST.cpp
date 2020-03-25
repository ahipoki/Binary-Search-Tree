#include <iostream>
#include "BST.h"
#include "Node.h"

using namespace std;

BST::BST(){//Constructor
  head = NULL;
  //Head node is NULL
}

void BST::Insert(int n){//Public insert function
  Insert(head, n);
  //Calls private insert function
}

void BST::Insert(Node* &h, int key){//Private insert function
  if (h == NULL){//If head is null
    head = new Node(key);
    //BST was empty & new head
    return;
  }
  else if (key < h->getKey()){//If key is less than current node, go left
    if (h->getLeft() == NULL){//If there's no node left
      h->setLeft(new Node(key));
      h->getLeft()->setParent(h);
      //Add the new node
      return;
    }
    Node* left = h->getLeft();
    Insert(left, key);
    //Call insert on left side again
    return;
  }
  else{//Anything else go to right
    if (h->getRight() == NULL){//If right side is empty
      h->setRight(new Node(key));
      h->getRight()->setParent(h);
      //Add new node
      return;
    }
    Node* right = h->getRight();
    Insert(right, key);
    //Call insert on right side again
    return;
  }
}

void BST::deleteNode(int n){//Public delete node function
  if(deleteNode(head, n)){
    cout<<"Node deleted"<<endl;
  }
  //Call private delete node function
}

bool BST::deleteNode(Node* &h, int n){//Private delete node function
  if (h == NULL){//If the node wasn't found
    cout<<"Empty tree or node not found"<<endl;
    //Tell the user the tree is empty or the node was not found
    return false;
    //Return false
  }
  if (h->getKey() == n){//If the node was found
    if (h->getLeft() == NULL && h->getRight() == NULL){//0 children
      if (h->getParent() == NULL){//If it's the root node
	Node* temp = h;
	h = NULL;
	delete temp;
	return true;
	//Delete the node and set the head to NULL
      }
      if (h == h->getParent()->getLeft()){
        h->getParent()->setLeft(NULL);
      }
      //Fix parent's child pointer
      else{
        h->getParent()->setRight(NULL);
      }
      delete h;
    }
    else if (h->getLeft() == NULL){//Right child
      if (h->getParent() == NULL){//If root node
	Node* temp = h;
	h = h->getRight();
	h->setParent(NULL);
	delete temp;
	return true;
	//Set to right node and fix parent pointer
      }
      Node* right = h->getRight();     
      if (h == h->getParent()->getLeft()){//Point child pointer to new child
	h->getParent()->setLeft(right);
      }
      else{
        h->getParent()->setRight(right);
      }
      right->setParent(h->getParent());
      delete h;
      //Fix parent pointer
    }
    else if (h->getRight() == NULL) {//Left child, do the same as was done for right child
      if (h->getParent() == NULL) {
	Node* temp = h;
	h = h->getLeft();
	h->setParent(NULL);
	delete temp;
	return true;
      }
      Node* left = h->getLeft();
      if (h == h->getParent()->getLeft()){//Point parent's child pointer to new child
        h->getParent()->setLeft(left);
      }
      else h->getParent()->setRight(left);
      left->setParent(h->getParent());
      delete h;
    }
    else {//2 children
      Node* temp = h->getRight();
      while (temp->getLeft()) {
	    temp = temp->getLeft();
      }
      int key = temp->getKey();
      deleteNode(temp, key);
      
      //Swap values
      h->setKey(temp->getKey());
    }
    return true;
    //Deleted so return true
  }

  if (n < h->getKey()) {//If key is less than this go right
    if (h->getLeft() == NULL) {//If nothing to left, key doesn't exist
      cout<<"Node not found"<<endl;
      //Node not found
      return false;
      //Return false
    }
    Node* t = h->getLeft();
    return deleteNode(t, n);
    //Delete node on left side
  }
  else {//If key is more, go right
    if (h->getRight() == NULL) {//Same as left
      cout<<"Node not found"<<endl;
      return false;
    }
    Node* t = h->getRight();
    return deleteNode(t, n);
  }
}

void BST::PrintTreeInOrder() {//Public print function
  PrintTreeInOrder(head, 0);
  //Call private print function
}

void BST::PrintTreeInOrder(Node* h, int d) {//Private print function
  if(!h){//If tree is empty
    return;
  }
  if (h->getLeft()){
    PrintTreeInOrder(h->getLeft(), d+1);
  }
  for (int i = 0; i < d; i++){
    cout<<"   ";
  }
  cout<<h->getKey()<<endl;
  if (h->getRight()){
    PrintTreeInOrder(h->getRight(), d+1);
  }
}

bool BST::search(int n) {//Public search function
  return search(head, n);
  //Call private search function
}

bool BST::search(Node* h, int n) {//Private search function
  if (!h){//If tree is empty
    return false;
    //Return false
  }
  if (h->getKey() == n){//Key matches
    return true;
  }
  if (n < h->getKey()){//If less, go left
    if (h->getLeft() == NULL){//If node not found
      return false;
      //Return false
    }
    return search(h->getLeft(), n);
    //Go left
  }
  else {//If greater, go right
    if (h->getRight() == NULL){//Node not found
      return false;
      //Return false
    }
    return search(h->getRight(), n);
    //Go right
  }
}

BST::~BST() {//Destructor
  while (head) {//Repeatedly call delete on head until the tree is gone
    deleteNode(head, head -> getKey());
    //Delete head
  }
}
