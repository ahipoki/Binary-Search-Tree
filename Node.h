#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <cstring>

using namespace std;

class Node{
  public:
   Node(int);
   ~Node();
   void setKey(int);
   int getKey();
   void setLeft(Node*);
   Node* getLeft();
   void setRight(Node*);
   Node* getRight();
  private:
   Node* Right;
   Node* Left;
   Node* Parent;
   int Key;
};
#endif
