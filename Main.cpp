#include <iostream>
#include <cstring>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include "Node.h"

using namespace std;

void strupper(char* str);
int strToInt(char* str);
void Insert(BST*);
void deleteNode(BST*);
void print(BST*);
void search(BST*);

int main()
{
  BST* bst = new BST();
  char input[80];
  char line[100];
  bool running = true;
  bool type = false;
  while (type == false){
    cout<<"Do you want to use input or a file?"<<endl;
    cin.getline(input, 80);
    strupper(input);
    if (strcmp(input, "INPUT") == 0){
      type = true;
      cout<<"Please enter a list of numbers between 1 and 999 separated by spaces"<<endl;
      cin.get(line, 100);
      cin.clear();
      cin.ignore(999, '\n');
    }
    else if (strcmp(input, "FILE") == 0){
      char fileName[100];
      cout<<"Enter a file name"<<endl;
      cin.getline(fileName, sizeof(fileName));
      ifstream fileStream;
      fileStream.open(fileName);
      if (fileStream){
	fileStream.getline(line, sizeof(line));
      }
      else{
	cout<<"Couldn't find that file"<<endl;
	return 0;
      }
      fileStream.close();
      type = true;
    }
    else{
      cout<<"That's an invalid option"<<endl;
    }
  }
  char* list = strtok(line, " ");
  int heap[100];
  int len = 0;
  while (list){
    heap[len] = atoi(list);
    heapify(heap, len);
    list = strtok(NULL, " ");
    len++;
  }
  while (running == true){
    char move[80];
    cout<<"Do you want to add a node, remove a node, print out the tree, search for a number in the tree, or quit the program?"<<endl;
    cin.getline(move, 80);
    strupper(move);
    if (strcmp(move, "ADD") == 0){
      int numAdd = 0;
      cout<<"What is the number you want to add to the tree?"<<endl;
      cin>>numAdd;
      cin.clear();
      cin.ignore(999, '\n');
      bst->Insert(numAdd);
    }
    else if (strcmp(move, "REMOVE") == 0){
      int numRemove = 0;
      cout<<"What is the number you want to remove?"<<endl;
      cin>>numRemove;
      cin.clear();
      cin.ignore(999, '\n');
      bst->deleteNode(numRemove);
    }
    else if (strcmp(move, "PRINT") == 0){
      cout<<"Visual Representation:"<<endl;
      printTree(heap, len, 0, 0);
      cout<<"Max to min:"<<endl;
      sort(heap, len);
      cout<<endl;
    }
    else if (strcmp(move, "SEARCH") == 0){
      int numSearch = 0;
      cout<<"Enter a number to search the tree for"<<endl;
      cin>>numSearch;
      cin.clear();
      cin.ignore(999, '\n');
      if (bst->search(numSearch)){
	      cout<<numSearch<<" is in the tree"<<endl;
      }
      else{
        cout<<numSearch<<" is not in the tree"<<endl;
      }
    }
    else if (strcmp(move, "QUIT") == 0){
      running = false;
    }
    else{
      cout<<"That's an invalid option"<<endl;
    }
  }
  delete bst;
}

void strupper(char* str){
  int len = strlen(str);
  for (int i = 0; i < len; i++){
    str[i] = toupper(str[i]);
  }
}

int strToInt(char* str){
  int num = 0;
  for (int i = 0; i < strlen(str); i++){
    if (!isdigit(str[i])){
      continue;
    }
    num *= 10;
    num += str[i] - '0';
  }
  return num;
}

void Insert(BST* bst){
  int key;
  cout<<"What number do you want to add to the tree?"<<endl;
  cin>>key;
  cin.clear();
  cin.ignore(999, '\n');
  bst->Insert(key);
}

void deleteNode(BST* bst){
  int key;
  cout<<"What number do you want to remove from the tree?"<<endl;
  cin>>key;
  cin.clear();
  cin.ignore(999, '\n');
  bst->deleteNode(key);
}

void print(BST* bst){
  bst->PrintTreeInOrder();
}

void search(BST* bst){
  int key;
  cout<<"What number do you want to search the tree for?"<<endl;
  cin>>key;
  cin.clear();
  cin.ignore(999, '\n');
  if (bst->search(key)){
    cout<<n<<" is in the tree"<<endl;
  }
  else{
    cout<<n<<" is not in the tree"<<endl;
  }
}
