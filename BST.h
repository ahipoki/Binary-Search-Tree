#ifndef BST_H
#define BST_H
#include <iostream>
#include <cstring>

using namespace std;

class BST{
  public:
    BST();
    Node* Insert(Node*, int);
    void PrintTreeInOrder(Node*);
    Node* Search(Node*, int);
    int FindMin(Node*);
    int FindMax(Node*);
    int Successor(Node*);
    int Predecessor(Node*);
    Node* Remove(Node*, int);
  private:
    int Key;
    Node* Left;
    Node* Right;
    Node* Parent;
};
#endif
