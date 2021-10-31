#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cstring>

void rprint(std::map<std::string,std::vector<std::string>> graphlist); //prints in reverse ASCII order                                                      

void aprint(std::map<std::string,std::vector<std::string>> graphlist); //prints in ascending ASCII order                                                    

void cprint(std::map<std::string,std::vector<std::string>> graphlist); //prints from largest to smallest, ties broken with ASCII

void printcontainingwords(int num, std::map<std::string,std::vector<std::string>> graphlist); //prints all keys with vectors of size num

int findphrase(std::string word, std::string phrase); //checks if a word contains a certain phrase                                                

std::string removepunctuation(std::string word); //removes . , ! ? from a word    

#endif
