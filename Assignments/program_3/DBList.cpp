#include <iostream>
#include <string>
#include <fstream>
#include "DBList.h"

using namespace std;

/**
 *Constructor
 */
DBList::DBList(){
  Head = NULL;
  Tail = NULL;
  Count = 0;
}

/**
 * InsertFront - 
 *     Inserts a value at the front of the list by calling 
 *     actual insert with a node.
 * Params:
 *     string : data element to be inserted
 */
void DBList::InsertFront(string Data){
  Node* Temp = new Node(Data);
  InsertFront(Temp);

}

/**
 * InsertFront - 
 *     Inserts a value at the front of the list
 * Params:
 *     Node*& : node to be appended to front
 */
void DBList::InsertFront(Node* &Temp){
  
  if(!Head){
    Head = Temp;
    Tail = Temp;
    Current = Temp;
    Tail->Next = Head;
    Tail->Prev = Head;
    Head->Next = Tail;
    Head->Prev = Tail;
    
  }else{
    Temp->Next = Head;
    Temp->Prev = Tail;
    Head->Prev = Temp;
    Tail->Next = Temp;
    Tail = Temp;
  }
  Count++;
}
/**
 * Delete - 
 *     Deletes a value in the lsit
 * Params:
 *     Node*& : Node to Delete.
 */

void DBList::Delete(Node* &temp){
  if(Head == Tail && Head->Data==temp->Data){
    delete Head;
    Head = NULL;
    Tail = NULL;
  //Beginning of list
  }else if(Head->Data == temp->Data){
    Head = Head->Next;
    delete Head->Prev;
    Head->Prev = Tail;
  //End of list
  }else if(Tail->Data == temp->Data){
    Tail = Tail->Prev;
    delete Tail->Next;
    Tail->Next = Head;
  //Middle of list
  }else{

    temp->Prev->Next = temp->Next;
    temp->Next->Prev = temp->Prev;
    delete temp;

  }
  Count--;
}


/**
 * Print - 
 *     Travereses and prints out list
 * Params:
 *     Nothing
 */
void DBList::Print(){
  Node *Temp = Head;
  
  while(Temp != Tail){
    cout<<Temp->Data<<" ";
    Temp = Temp->Next;
  }
}
/**
 * getmulti- 
 *     gets  the multi and word length and sends to the traverse function.
 * Params:
 *     ifstream &infile, ofstream & outfile
 */

//Gets multiple and word length multiples and sends to treaverse function.
void DBList::getmulti(ifstream &infile, ofstream &outfile){
  int jumps, length;
  string a;
  
  cout <<endl << "Please enter multiplyer " << endl;
  cin >> jumps;
  
  while(!infile.eof()){
    infile >> a;
    length = a.length();
    traverse(jumps *length, outfile);
  }
}
/**
 * getmulti- 
 *     gets  the multi and word length and sends to the traverse function.
 * Params:
 *     ifstream &infile, ofstream & outfile
 */
void DBList::traverse(int jumps, ofstream &outfile){
  Node*Temp;
  if(Count > 1){
    for(int i = 1; i <= jumps; i++){
      if(jumps % 2 == 0){
        Current = Current->Next;
      }
      else{
        Current = Current->Prev;
      }
    }
    Temp = Current;
    Current = Current->Next;
    outfile <<"Deleting:"<<Temp->Data<<endl;
    DBList::Delete(Temp);

  }
  if(Head->Data == Tail->Data){
    outfile << "winner is : " << Head->Data  << endl;
    Count--;
  }
 }



