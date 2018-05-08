#include <iostream>
#include <string>

using namespace std;

struct Node{
  string Data;

  Node *Prev;
  Node *Next;
  Node(string x){
      Data = x;
      Prev = NULL;
      Next = NULL;
  }
};

class DBList{
private:
    int Count;
    Node *Head;
    Node *Tail;
    Node *Current;
    void rPrint(Node*);
    void rPrint1(Node*);
public:
    DBList();
    void InsertFront(string);
    void InsertFront(Node*&);
    void InsertRear(string);
    void InsertRear(Node*&);
    void InsertInOrder(string);
    void PriorityInsert(string Data);
    void Delete(Node *&);   //Removes item from list
    bool Find(string);     //Locate and see if exists

    void Print();
    void Print(int);
    void rPrint();
    void traverse(int, ofstream &outfile);
    void getmulti(ifstream &infile, ofstream &outfile);

};