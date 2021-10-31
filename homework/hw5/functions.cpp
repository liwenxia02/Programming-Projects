#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cstring>
#include "functions.h"

using std::cout;
using std::string;
using std::endl;
using std::map;
using std::vector;

void printcontainingwords(int num, std::map<std::string,std::vector<std::string>> graphlist){
  //prints out the key and values when the length of values is equal to the given num
  int numprinted = 0;
  for(map<string, vector<string>>::iterator it = graphlist.begin(); it!=graphlist.end(); ++it){
    if((int)(it->second).size()==num){ //checks if size is equal to the num we want to print out
      numprinted ++;
      cout << it->first << ": [";
      for(vector<string>::iterator vit = (it->second).begin(); vit!=(it->second).end(); vit++){
        cout << *vit;
        if(vit+1!=(it->second).end()){ //prints comma if element is not the final element                                                        
          cout << ", ";
        }
      }
    cout << "]" << endl;
    }
  }
  if(numprinted==0){ //if we didn't print anything
    cout <<"None"<<endl;
  }
}

void printnumandwords(string digraph, std::map<std::string,std::vector<std::string>> graphlist){
  //prints number of words the containing the digraph and all words inluding the digraph
  cout << graphlist[digraph].size() << ": [";
  for(vector<string>::iterator vit = graphlist[digraph].begin(); vit!=graphlist[digraph].end(); vit++){
    cout << *vit;
    if(vit+1!=graphlist[digraph].end()){ //prints comma if element is not the final element                                                      
      cout << ", ";
    }
  }
  cout << "]" << endl;
}

void cprint(map<string,vector<string>> graph){
  //uses recursion to print all elements from largest to smallest, using ASCII as the tiebreaker
  map<string,vector<string>> graphlist = graph;
  size_t largestlength = 0;
  string currentkey = graphlist.begin()->first;
  for(map<string, vector<string>>::iterator it = graphlist.begin(); it!=graphlist.end(); ++it){
    //finds the longest digraph/trigraph in ASCII order                                                                                 
    if (largestlength < (it->second).size()){
      largestlength = (it->second).size();
      currentkey = it->first;
    }
  }
  //prints the longest vector of values and the words that contain it                                                                   
  cout << currentkey << ": [";
  for(vector<string>::iterator vit = graphlist[currentkey].begin(); vit!=graphlist[currentkey].end(); vit++){
    cout << *vit;
    if(vit+1!=graphlist[currentkey].end()){
      cout << ", ";
    }
  }
  cout << "]" <<endl;
  graphlist.erase(currentkey);
  if(!graphlist.size()==0){
    cprint(graphlist);
  }
}

void aprint(map<string,vector<string>> graphlist){
  //prints everything in ascending ASCII order                                                                                          
  for(map<string, vector<string>>::iterator it = graphlist.begin(); it!=graphlist.end(); ++it){
    cout << it->first << ": [";
    for(vector<string>::iterator vit = (it->second).begin(); vit!=(it->second).end(); vit++){
      cout << *vit;
      if(vit+1!=(it->second).end()){ //prints comma if element is not the final element                                                 
        cout << ", ";
      }
    }
    cout << "]" << endl;
  }
}

void rprint(map<string,vector<string>> graphlist){
  //prints everything in reverse ASCII order                                                                                            
  for(map<string, vector<string>>::reverse_iterator it = graphlist.rbegin(); it!=graphlist.rend(); ++it){
    cout << it->first << ": [";
    for(vector<string>::iterator vit = (it->second).begin(); vit!=(it->second).end(); vit++){
      cout << *vit;
      if(vit+1!=(it->second).end()){ //prints comma if element is not the final element                                                 
        cout << ", ";
      }
    }
    cout << "]" << endl;
  }
}

int findphrase(string word, string phrase){
  //returns 1 if phrase is found in word, else 0                                                                                        
  std::size_t found = word.find(phrase);
  if(found!=std::string::npos){
    return 1;}
  return 0;
}

string removepunctuation(string word){
  //gets rid of . , ! ? from word                                                                                                       
  word.erase(remove(word.begin(), word.end(), '.'), word.end());
  word.erase(remove(word.begin(), word.end(), ','), word.end());
  word.erase(remove(word.begin(), word.end(), '!'), word.end());
  word.erase(remove(word.begin(), word.end(), '?'), word.end());
  return word;
}

