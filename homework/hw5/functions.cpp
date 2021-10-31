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

void cprint(map<string,vector<string>> graphlist){
  //uses recursion to print all elements from largest to smallest, using ASCII as the tiebreaker                                        
  size_t largestlength = 0;
  string currentkey;
  for(map<string, vector<string>>::iterator it = graphlist.begin(); it!=graphlist.end(); ++it){
    //finds the longest digraph/trigraph in ASCII order                                                                                 
    if (largestlength < (it->first).length()){
      largestlength = (it->first).length();
      currentkey = it->first;
    }
  }
  //prints the longest digraph/trigraph and the words that contain it                                                                   
  cout << currentkey << ": [";
  for(vector<string>::iterator vit = graphlist[currentkey].begin(); vit!=graphlist[currentkey].end(); vit++){
    cout << *vit;
    if(vit+1!=graphlist[currentkey].end()){
      cout << ", ";
    }
  }
  cout << "]" <<endl;
  graphlist.erase(currentkey);
  if(!graphlist.empty()){
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

