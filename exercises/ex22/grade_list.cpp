#include "grade_list.h"
#include <algorithm>
#include <cassert>
#include <vector>

using std::sort;
using std::vector;
// You will add function definitions to this file.
// See TODOs in grade_list.h.

// The "percentile" member function was declared
// (prototyped) in the GradeList class definition.
// But the implementation wasn't given there.  Here
// we give the definition.

// When we define a member function outside the class
// definition, we write the function name as
// <class name>::<member function name>.  E.g. here
// we write "GradeList::percentile"

/////////////////////////////////////////////////////////

// Retrieve grade at the given percentile.  
// This function is complete.
double GradeList::percentile(double percentile) {
  assert(percentile >= 0 && percentile <= 100.0);
  if (!is_sorted) {
    sort(grades.begin(), grades.end());
    is_sorted = true;
  }
  size_t select = percentile / 100.0 * grades.size();
  // Handle case where percentile == 100.0
  if (select == grades.size()) {
    select = grades.size()-1;
  }
  return grades[select];
}

  // TODO: define this function in grade_list.cpp                                                          
double GradeList::mean(void){
  double sum = 0.0;
  for(vector<double>::iterator it = grades.begin(); it !=grades.end(); it++){
    sum+=*it;
  }
  return sum/(double)(grades.size());
}

  // TODO: define this function in grade_list.cpp                                                          
  // Hint: median = 50th percentile                                                                        
double GradeList::median(void){
  return percentile(50.0);
}

std::vector<double>GradeList::mygrades(void){
  return grades;
}
