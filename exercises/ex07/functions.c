#include <stdio.h>
#include <math.h>

float div(float a, float b);
float mult(float a, float b);
long fac(int a);
int bsearch(float ra[], int low, int high, float target);
int bsearch2(float ra[], int low, int high, float target,float results[],int size); 

int main() {
  float a = 5, b = 8;
  printf("%f divided by %f is %f\n", a, b, div(a, b));

  // Part 2 - to test mult
  printf("%f x %f is %f (expected 40)\n", a, b, mult(a, b));

  // Part 2 - to test fac
  printf("factorial of -4 is %ld (expected 0)\n", fac(-4));
  printf("factorial of 10 is %ld (expected 3628800)\n", fac(10));

  // Part 3 - to test bsearch
  float myray[] = {3.4, 4.5, 5.6, 6.7, 7.8, 8.9, 9.0, 10, 15, 20, 25, 100};
  int capacity = sizeof(myray) / sizeof(myray[0]);
  int where = bsearch(myray, 0, capacity-1, 5.6);
  printf("binary search of 5.6 found at index: %d\n", where);
  where = bsearch(myray, 0, capacity-1, 30);
  printf("binary search of 30 found at index: %d\n", where);

  // Part 3 - to test bsearch2
  float results[12] = {0};
  where = bsearch2(myray, 0, capacity-1, 10, results, 0);
  printf("binary search of 10 found at index: %d\n", where);
  printf("results array is: " );
  for (int i = 0; i < capacity; i++) {
    printf("%.1f ", results[i]);
  }
  printf("\n");

  return 0;
}

float mult(float a, float b){
  return a*b;
}

float div(float a, float b) {
  return a / b;
}

long fac(int a){
  if (a<0){
    return 0;
  }
  if (a==0){
    return 1;
  }
  return fac(a-1)*a;
}
  
int bsearch(float ra[], int low, int high, float target){
  if(high>low){
  int midpoint = (int) floor((high + low)/2);
  if(ra[midpoint]>target){
    return bsearch(ra,low,midpoint-1,target);
  }
  if(ra[midpoint]<target){
    return bsearch(ra,midpoint+1,high,target);
  }
  if(ra[midpoint]==target){
    return midpoint;
  }
  }
  return -1;
}

int bsearch2(float ra[], int low, int high, float target, float results[],int size){
  if(high<low)
    return -1;
  int mid = (low+high)/2;
  results[size]=ra[mid];
  if(target<ra[mid])
    return bsearch2(ra,low,mid-1,target,results,size+1);
  else if(ra[mid]<target)
    return bsearch2(ra,mid+1,high,target,results,size+1);
  else return mid;
   }

