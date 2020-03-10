#include <iostream>
#include <cstring>
#include "Node.h"

using namespace std;

Node::Node(char* newValue){
  value = new char[strlen(newValue)+1];
  strcpy(value, newValue);
  right = NULL;
  left = NULL;
  next = NULL;
}

void Node::setNext(Node* newNext){
  next = newNext;
}

Node* Node::getNext(){
  return next;
}

Node::~Node(){
  delete[] value;
  next = NULL;
}

char* Node::getValue(){
  return value;
}

void Node::setLeft(Node* newLeft){
  left = newLeft;
}

Node* Node::getLeft(){
  return left;
}

void Node::setRight(Node* newRight){
  right = newRight;
}

Node* Node::getRight(){
  return right;
}
