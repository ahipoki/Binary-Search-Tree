#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <cstring>

using namespace std;

class Node{
  Node();
  ~Node();
  void setNext(Node*);
  Node* getNext();
}
