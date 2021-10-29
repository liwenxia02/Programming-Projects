#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>
// PART 7 TO DO: Make sure to include any additional necessary header files
#include <algorithm>
void sort( std::vector< int > *values );

int main( void )
{
  std::vector< int > vec1 , vec2;
  size_t count;

  std::cout << "Enter the count: ";
  std::cin >> count;

  vec1.resize( count );
  for( size_t i=0 ; i<count ; i++ ) vec1[i] = i;

  vec2 = vec1;


  std::chrono::steady_clock::time_point begin1 = std::chrono::steady_clock::now();
  sort( &vec1 );
  std::chrono::steady_clock::time_point end1 = std::chrono::steady_clock::now();
 

  std::chrono::steady_clock::time_point begin2 = std::chrono::steady_clock::now();
  // PART 7 TO DO: Use the implementation of sort from STL to sort the contents of "vec2"
  std::sort( vec2.begin() , vec2.end() );
  std::chrono::steady_clock::time_point end2 = std::chrono::steady_clock::now();
   

  for( size_t i=1 ; i<vec1.size() ; i++ ) assert( vec1[i-1]<=vec1[i] );
  for( size_t i=1 ; i<vec2.size() ; i++ ) assert( vec2[i-1]<=vec2[i] );
  
  std::cout << "Your sort time = " << std::chrono::duration_cast<std::chrono::milliseconds>(end1 - begin1).count() << "(ms)" << std::endl;
  std::cout << "STL's sort time = " << std::chrono::duration_cast<std::chrono::milliseconds>(end2 - begin2).count() << "(ms)" << std::endl;
  
  return 0;
}

void sort( std::vector< int > *values )
{
  // PART 6 TO DO: Copy your implementation of the sort function from ex18 here
  if (values->size()>1){
    int mid = values->size()/2;
    std::vector< int > left(mid);
    std::vector< int > right(values->size()-mid);
    for(int i = 0; i < mid; i++) {left[i] = (*values)[i];}
    for(int i = mid; i < (int)values->size(); i++) {right[i-mid]=(*values)[i];}
    sort( &left);
    sort( &right);
    size_t idx = 0, i = 0, j = 0;
    while(i<left.size() || j <right.size()){
      if(i>=left.size()) {(*values)[idx++]=right[j++];}
      else if(j>=right.size()) {(*values)[idx++] = left[i++];}
      else if (left[i]<=right[j]) {(*values)[idx++] = left[i++];}
               else {(*values)[idx++] = right[j++];}
    }
  }
}

