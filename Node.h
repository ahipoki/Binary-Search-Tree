#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <cstring>

using namespace std;

class Node{
  public:
   Node(char*);
   ~Node();
   void setKey(char*);
   char* getKey();
   void setLeft(Node*);
   Node* getLeft();
   void setRight(Node*);
   Node* getRight();
  private:
   Node* right;
   Node* left;
   Node* parent;
   int key;
};
#endif
