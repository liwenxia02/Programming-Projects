#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cstring>

using std::cout;
using std::string;
using std::endl;
using std::map;
using std::vector;

void rprint(map<string,vector<string>> graphlist); //prints in reverse ASCII order

void aprint(map<string,vector<string>> graphlist); //prints in ascending ASCII order  

void cprint(map<string,vector<string>> graphlist); //prints from largest to smallest, ties broken with ASCII

int findphrase(string word, string phrase); //checks if a word contains a certain phrase

string removepunctuation(string word); //removes . , ! ? from a word

int main(int argc, char * argv[]) {
  // if number of arguments is not correct, exit with code 1!
  if (argc != 3) {
    cout<<"Invalid arguments";
    return 1;
  }

  // if the "order" argument is not valid, exit with code 1!
  string order(argv[2]);
  if (order != "r" && order != "a" && order != "c") {
    cout<<"Invalid arguments";
    return 1;
  }
  

  // TODO: WRITE CODE
  
  std::ifstream ifile(argv[1]); //opens file to read from
  string word;
  int num;
  ifile>>num;
  
  //save the digraphs/trigraphs into an array
  vector<string> graphs;
  for(int i = 0; i < num; i++){
    ifile>>word;
    graphs.push_back(word);
  }


  //fills the map with all digraph/trigraphs from vector graphs in the input file
  //could not make this a separate function because could not pass ifstream as parameter
  map<string, vector<string>> graphlist;
  for(int i = 0; i < num; i++){
    graphlist[graphs[i]]; //initializes the map with each and every digraph/trigraph
  }
  while(ifile>>word){
    //check if the current word has any digraph or trigraph, then updates map
    word = removepunctuation(word); //gets rid of punctuation
    transform(word.begin(),word.end(),word.begin(), ::tolower); //makes string lowercase
    for(size_t i = 0; i < graphs.size(); i++){
      if(findphrase(word, graphs[i])){
        graphlist[graphs[i]].push_back(word); //adds to the map if the digraph or trigraph is in the word      
      } 
    }
  }

  //print map depending on which letter is given in the argument
  if(!strcmp(argv[2],"a")){
    aprint(graphlist);
  }
  else if(!strcmp(argv[2],"r")){
    rprint(graphlist);
  }
  else if(!strcmp(argv[2],"c")){
    cprint(graphlist);
  }
  return 0;
}
//end of main 

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
