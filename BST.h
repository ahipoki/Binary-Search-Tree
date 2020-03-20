#ifndef BST_H
#define BST_H
#include <iostream>
#include <cstring>

using namespace std;

class BST{
  public:
    BST();
    void Insert(int);
    void PrintTreeInOrder();
    bool Search(int);
    void Delete(int);
    ~BST();
  private:
    int Key;
    Node* Left;
    Node* Right;
    Node* Parent;
};
#endif
