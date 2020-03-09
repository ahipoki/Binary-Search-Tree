#include <iostream>
#include <cstring>

using namespace std;

void strupper(char* str);
void sort(int[], int);
void printTree(int[], int, int, int);
void heapify(int[], int);
void heapDown(int[], int, int);

int Main()
{
  cout<<"Binary Search Tree"<<endl;
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
