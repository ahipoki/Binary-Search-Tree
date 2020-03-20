#include <iostream>
#include <cstring>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include "Node.h"
#include "BST.h"

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
    //Ask if they want to use input or a file
    cin.getline(input, 80);
    //Get their choice
    strupper(input);
    //Make it uppercase
    if (strcmp(input, "INPUT") == 0){//If they said input
      type = true;
      cout<<"Please enter a list of numbers between 1 and 999 separated by spaces"<<endl;
      //Ask them for a list of numbers between 1 and 999
      cin.get(line, 100);
      //Get their input
      cin.clear();
      cin.ignore(999, '\n');
    }
    else if (strcmp(input, "FILE") == 0){//If they said file
      char fileName[100];
      cout<<"Enter a file name"<<endl;
      //Ask them for a file name
      cin.getline(fileName, sizeof(fileName));
      //Get their input
      ifstream fileStream;
      fileStream.open(fileName);
      if (fileStream){//Open the file
	fileStream.getline(line, sizeof(line));
      }
      else{//If that file isn't found
	cout<<"Couldn't find that file"<<endl;
	//Tell them it couldn't be found
	return 0;
      }
      fileStream.close();
      //Close the file
      type = true;
    }
    else{//Anything else
      cout<<"That's an invalid option"<<endl;
      //Tell them that's an invalid option
    }
  }
  char* build = new char[strlen(line)+1]();
  int ind = 0;
  for (int i = 0; i < strlen(line); i++){
    if (line[i] == ' '){
      if (strlen(build) > 0){
        bst->Insert(strToInt(build));
      }
      build = new char[strlen(line)]();
      ind = 0;
    }
    else{
      if (isdigit(line[i])){
        build[ind++] = line[i];
      }
    }
  }
  if (strlen(build) > 0){
    bst->Insert(strToInt(build));
  }
  while (running == true){//While the program is running
    char move[80];
    cout<<"Do you want to add a node, remove a node, print out the tree, search for a number in the tree, or quit the program?"<<endl;
    //Ask them what they want to do
    cin.getline(move, 80);
    //Get their input
    strupper(move);
    if (strcmp(move, "ADD") == 0){//If they said add
      Insert(bst);
      //Add node
    }
    else if (strcmp(move, "REMOVE") == 0){//If they said remove
      deleteNode(bst);
      //Remove node
    }
    else if (strcmp(move, "PRINT") == 0){//If they said print
        print(bst);
	//Print tree
    }
    else if (strcmp(move, "SEARCH") == 0){//If they said search
      search(bst);
      //Search the tree
    }
    else if (strcmp(move, "QUIT") == 0){//If they said quit
      running = false;
      //Stop the program
    }
    else{//Anything else
      cout<<"That's an invalid option"<<endl;
      //That's invalid
    }
  }
  delete bst;
}

void strupper(char* str){//Make input uppercase
  int len = strlen(str);
  for (int i = 0; i < len; i++){
    str[i] = toupper(str[i]);
  }
}

int strToInt(char* str){//Convert char strings to int
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

void Insert(BST* bst){//Add node
  int key;
  cout<<"What number do you want to add to the tree?"<<endl;
  //Ask for a key
  cin>>key;
  cin.clear();
  cin.ignore(999, '\n');
  bst->Insert(key);
}

void deleteNode(BST* bst){//Delete node
  int key;
  cout<<"What number do you want to remove from the tree?"<<endl;
  //Ask for a key
  cin>>key;
  cin.clear();
  cin.ignore(999, '\n');
  bst->deleteNode(key);
}

void print(BST* bst){//Print tree
  bst->PrintTreeInOrder();
}

void search(BST* bst){//Search the tree
  int key;
  cout<<"What number do you want to search the tree for?"<<endl;
  //Ask for a key
  cin>>key;
  cin.clear();
  cin.ignore(999, '\n');
  if (bst->search(key)){
    cout<<key<<" is in the tree"<<endl;
  }
  else{
    cout<<key<<" is not in the tree"<<endl;
  }
}
