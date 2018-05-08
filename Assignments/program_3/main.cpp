//////////////////////////////////////////////////////////////////////////
// Title:            Survival of the lucky
// Files:            main.cpp DBList.cpp, DBList.h, animals.txt, eliminated.txt
// Semester:         (1063 data structures ) Spring 2018
//
// Author:           (Logan Wheeler)
// Email:            (lbw98@att.net)
// Description: The problem is based on Flavius Josephus, a Jewish historian living
// in the 1st century. According to Josephus' account of the siege of Yodfat, he and his 40 comrade soldiers were trapped in a cave, surrounded by Romans. They chose suicide over capture and decided that they would form a circle and start killing themselves using a step of three. Josephus states that by luck, or maybe by the hand of God, he and another man remained the last and gave up to the Romans. Wikipedia

// So, Josephus was in the right place, at the right time (quite literally). More     simply put, the problem is to find the correct location in the circle so that you  will be a survivor at the end. We will identify the correct spot to be (or the     person who will survive) by following the example below:
//       
//
///////////////////////////////////////////////////////////////////


#include <iostream>
#include <fstream>
#include <string>
#include "DBList.h"

using namespace std;

int main() {
    srand(93487);
    DBList List;
    string a;
    int count = 0;

    
    ifstream infile("animals.txt");
    ofstream outfile("eliminated.txt");
    
    //Inserts items to the Front.
    while(!infile.eof()){
      infile>>a;
      count++;
      List.InsertFront(a);
      
    }
    
    cout<<endl;
    
    //Clears infile.
    infile.clear();
    infile.seekg(0, std::ios::beg);
    
    //Prints out list
    List.Print();
    
    //gets multi and length does everything from there
    List.getmulti(infile,outfile);
}
