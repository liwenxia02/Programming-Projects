#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cstring>
#include "functions.h"
#include <sstream>

using std::stringstream;
using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::map;
using std::vector;

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

  //portion where the user can input a number, a digraph, or the word exit
  string userinput;
  while(cout<<"q?>", cin>>userinput){
    if (!strcmp(userinput.c_str(), "exit")){ //ends the program if exit is typed
      return 0;
    }
    stringstream ss1(userinput);
    int ival;
    if(ss1>>ival){ //checks if userinput is an integer
      printcontainingwords(ival,graphlist);
    }
  }
  return 0;
}
//end of main 
