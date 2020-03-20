#ifndef BST_H
#define BST_H
#include "Node.h"

class BST {
 public:
  BST();
  //Constructor
  void Insert(int);
  //Insert a node
  void deleteNode(int);
  //Delete a node
  void PrintTreeInOrder();
  //Print the tree
  bool search(int);
  //Search the tree
  ~BST();
  //Destructor
 private:
  void Insert(Node*&, int);
  bool deleteNode(Node*&, int);
  void PrintTreeInOrder(Node*, int);
  bool search(Node*, int);
  Node* head;
};
#endif
