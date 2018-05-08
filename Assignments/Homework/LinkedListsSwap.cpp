#include <iostream>

using namespace std;

struct Node{
  int data;
  Node* next;
  
  Node(){
    data = 0;
    next = NULL;
  }
};

class List{
private:
  Node* Head;
  
public:
  List() {
    Head = NULL;
  }
  
  
  void Insert(int x){
    if(Head == NULL){
      Head = new Node;
      Head-> data = x;
    }
    else{
        Node* temp = new Node;
        temp-> data = x;
        temp-> next = Head;
        Head = temp;

    }
  }
  
    void swapNeighbors(){
    Node* prev = Head;
    Node* temp = Head->next;
    int tempvar;
    
    while(temp->next){
      tempvar = temp->data;
      temp->data = prev->data;
      prev->data = tempvar;
      
      prev = prev->next->next;
      temp = temp->next->next;
      
    }
      tempvar = temp->data;
      temp->data = prev->data;
      prev->data = tempvar;
      
      prev = prev->next->next;
      temp = temp->next;
  }
  
  
  
  void Print(){
    Node* temp = Head;
    
    while(temp != NULL){
      cout << temp->data << " ";
      temp = temp->next;
      }
    }
  };

int main() {
  List L;
  
  for(int i = 0; i < 10; i++){
    L.Insert(rand()%10);
  }
  L.Print();
  L.swapNeighbors();
  cout << endl;
  L.Print();
}