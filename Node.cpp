#include <iostream>
#include <cstring>
#include "Node.h"

using namespace std;

Node::Node(int key){
  Key = key;
  Right = NULL;
  Left = NULL;
  Parent = NULL;
}

void Node::setKey(int key){
  Key = key;
}

int Node::getKey(){
  return Key;
}

void Node::setLeft(Node* left){
  Left = left;
}

Node* Node::getLeft(){
  return Left;
}

void Node::setRight(Node* right){
  Right = right;
}

Node* Node::getRight(){
  return Right;
}

Node* Node::setParent(Node* parent){
  Parent = parent;
}

Node* Node::getParent(){
  return Parent;
}

Node::~Node(){
  
}
