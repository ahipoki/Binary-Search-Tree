#include <iostream>
#include <cstring>
#include "Node.h"

using namespace std;

Node::Node(int newKey){
  Key = new char[strlen(newKey)+1];
  strcpy(Key, newKey);
  Right = NULL;
  Left = NULL;
  Parent = NULL;
}

void Node::setKey(int newKey){
  Key = newKey;
}

int Node::getKey(){
  return Key;
}

void Node::setLeft(Node* newLeft){
  Left = newLeft;
}

Node* Node::getLeft(){
  return Left;
}

void Node::setRight(Node* newRight){
  Right = newRight;
}

Node* Node::getRight(){
  return Right;
}

Node* Node::setParent(Node* newParent){
  Parent = newParent;
}

Node* Node::getParent(){
  return Parent;
}

Node::~Node(){
  
}
