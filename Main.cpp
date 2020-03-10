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
  char input[80];
  char line[100];
  bool type = false;
  while (type == false){
    cout<<"Do you want to use input or a file?"<<endl;
    cin.getline(input, 80);
    strupper(input);
    if (strcmp(input, "INPUT") == 0){
      type = true;
      cout<<"Please enter a list of numbers between 1 and 1000 separated by spaces"<<endl;
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
    heap[len];
    heapify(heap, len);
    list = strtok(NULL, " ");
    len++;
  }
  cout<<"Visual Representation:"<<endl;
  printTree(heap, len, 0, 0);
  cout<<"Max to min:"<<endl;
  sort(heap, len);
  cout<<endl;
  return 0;
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