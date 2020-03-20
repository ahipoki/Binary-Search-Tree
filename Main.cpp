#include <iostream>
#include <cstring>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include "Node.h"

using namespace std;

void strupper(char* str);
void sort(int[], int);
void printTree(int[], int, int, int);
void heapify(int[], int);
void heapDown(int[], int, int);

int main()
{
  BST* bst = new BST();
  char input[80];
  char line[100];
  int size = 0;
  int counter = 0;
  //int lineCounter = 0;
  bool running = true;
  bool type = false;
  while (type == false){
    cout<<"Do you want to use input or a file?"<<endl;
    cin.getline(input, 80);
    strupper(input);
    if (strcmp(input, "INPUT") == 0){
      type = true;
      cout<<"Please enter a list of numbers between 1 and 1000 separated by spaces"<<endl;
      cin.get(line, 100);
      size = sizeof(line)/sizeof(line[0]);
      for (int i = 0; i < size; i++){
	if (line[i] > 1000){
	  cout<<"You can't have numbers larger than 1000"<<endl;
	}
	else if (line[i] <= 1000){
	counter++;
	}
      }
      if (counter < size){
	cout<<"Repick your numbers"<<endl;
      }
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
    cout<<"Do you want to add a node, remove a node, print out the tree, search for a number in the tree, or stop the program?"<<endl;
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
    else if (strcmp(move, "STOP") == 0){
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

void sort(int heap[], int len){
  int originalLen = len;
  for (int i = 0; i < originalLen; ++i){
    cout<<heap[0]<<" ";
    int last = heap[len-1];
    heap[0] = last;
    len--;
    heapDown(heap, len, 0);
  }
}

void printTree(int heap[], int len, int depth, int ind){
  if (ind*2+1 < len){
    printTree(heap, len, depth+1, ind*2+1);
  }
  for (int i = 0; i < depth; i++){
    cout<<"     ";
  }
  cout<<heap[ind]<<endl;
  if (ind*2+2 < len){
    printTree(heap, len, depth+1, ind*2+2);
  }
}

void heapDown(int heap[], int len, int in){
  int largest = in;
  int l = 2*in+1;
  int r = 2*in+2;
  if (l < len && heap[l] > heap[largest]){
    largest = l;
  }
  if (r < len && heap[r] > heap[largest]){
    largest = r;
  }
  if (largest != in){
    swap(heap[in], heap[largest]);
    heapDown(heap, len, largest);
  }
}

void heapify(int heap[], int len){
  int parent = len/2;
  if (heap[len] > heap[parent] && len > 0){
    swap(heap[len], heap[parent]);
    heapify(heap, parent);
  }
}
