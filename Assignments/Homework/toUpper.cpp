#include <iostream>
#include <string>

using namespace std;

string tolower(string w){
  for(int i=0;i<w.length();i++){
    
    if((int)w[i]>=97 && (int)w[i]<=122){
      w[i] = w[i]-32;
    }
  }
  return w;
}


int main() {
  string x = "antelope";
 cout<<x<<endl;
  cout<<tolower(x)<<endl;
}