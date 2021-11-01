#include "grade_list.h"
#include <iostream>
#include <cassert>
#include <vector>/**
 * Hint: resolve the TODOs in grade_list.h first.
 * 
 * TODO: Write a program that declares a GradeList
 *       variable and adds to it all the even
 *       numbers 0-100:
 *       
 *       {0, 2, 4, ..., 98, 100}
 * 
 *       then prints out the minimum, maximum,
 *       median, mean and 75th percentile, all
 *       nicely labelled.
 */
using std::cout;
using std::endl;
using std::vector;

int main(void) {
  GradeList gl;
  for(double i = 0.0; i <=100.0; i++){
    gl.add(i);
    i++;
  }
  double min_so_far = 100.0;
  for (size_t i = 0; i < gl.mygrades().size(); i++) {
    if (gl.mygrades()[i] < min_so_far) {
      min_so_far = gl.mygrades()[i];
    }
  }
  cout<< "Minimum: " << min_so_far<<endl;
  double max_so_far = 0.0;
  for (size_t i = 0; i < gl.mygrades().size(); i++) {
    if (gl.mygrades()[i] > max_so_far) {
      max_so_far = gl.mygrades()[i];
    }
  }
  cout<< "Maximum: " << max_so_far<<endl;
  cout<< "Median: " << gl.median()<<endl;
  cout<< "Mean: " << gl.mean()<<endl;
  cout<< "75th Percentile: " <<gl.percentile(75.0)<<endl;
  return 0;
}
